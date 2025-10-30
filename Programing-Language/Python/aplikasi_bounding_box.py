import tkinter as tk
from tkinter import filedialog, messagebox, simpledialog, Toplevel, Button, colorchooser
import os
import json
from PIL import Image, ImageTk

class BoundingBoxApp:
    def __init__(self, root):
        self.root = root
        self.root.title("CropS.UX - Editor Bounding Box and Save image (v15.0 - Final)")
        self.root.geometry("1366x768")

        # Variabel State
        self.image_path, self.pil_image, self.tk_image = None, None, None
        self.boxes, self.guides = [], []
        self.selected_box_index, self.selected_guide_index = None, None
        self.mode, self.drag_start_pos = None, None
        self.current_rect_id, self.info_text_id = None, None
        self.zoom_factor, self.offset_x, self.offset_y = 1.0, 0, 0

        self.config = { 'COLOR_DEFAULT': 'red', 'COLOR_FOCUSED': 'black', 'COLOR_INFO_TEXT': 'black', 'COLOR_GUIDE': 'blue', 'HITBOX_MARGIN': 5 }
        self.edit_mode = tk.StringVar(value="create")

        self._setup_ui()

    def _setup_ui(self):
        menubar = tk.Menu(self.root); self.root.config(menu=menubar)
        settings_menu = tk.Menu(menubar, tearoff=0); menubar.add_cascade(label="Pengaturan", menu=settings_menu)
        settings_menu.add_command(label="Ubah Warna Box Default...", command=lambda: self.change_color('COLOR_DEFAULT'))
        settings_menu.add_command(label="Ubah Warna Box Fokus...", command=lambda: self.change_color('COLOR_FOCUSED'))
        settings_menu.add_command(label="Ubah Warna Info Teks...", command=lambda: self.change_color('COLOR_INFO_TEXT'))
        settings_menu.add_command(label="Ubah Warna Guide...", command=lambda: self.change_color('COLOR_GUIDE'))

        top_frame = tk.Frame(self.root); top_frame.pack(side=tk.TOP, fill=tk.X, padx=10, pady=5)
        main_frame = tk.Frame(self.root); main_frame.pack(fill=tk.BOTH, expand=True, padx=10, pady=10)
        status_frame = tk.Frame(self.root, relief=tk.SUNKEN, bd=1); status_frame.pack(side=tk.BOTTOM, fill=tk.X)

        tk.Button(top_frame, text="Muat Gambar", command=self.load_image).pack(side=tk.LEFT, padx=5)
        tk.Button(top_frame, text="Simpan Proyek (.sux)", command=self.save_project).pack(side=tk.LEFT, padx=5)
        tk.Button(top_frame, text="Muat Proyek (.sux)", command=self.load_project).pack(side=tk.LEFT, padx=5)
        tk.Button(top_frame, text="Export Semua Box", command=self.export_boxes, bg="#4CAF50", fg="white").pack(side=tk.LEFT, padx=20)

        control_frame = tk.Frame(main_frame, width=320); control_frame.pack(side=tk.LEFT, fill=tk.Y, padx=(0, 10)); control_frame.pack_propagate(False)
        mode_frame = tk.LabelFrame(control_frame, text="Mode"); mode_frame.pack(fill=tk.X, pady=5)
        tk.Radiobutton(mode_frame, text="Buat Box", variable=self.edit_mode, value="create", command=self.clear_all_focus).pack(side=tk.LEFT, padx=10)
        tk.Radiobutton(mode_frame, text="Edit/Pindah", variable=self.edit_mode, value="edit", command=self.clear_all_focus).pack(side=tk.LEFT, padx=10)

        manual_frame = tk.LabelFrame(control_frame, text="Edit & Buat Box Manual"); manual_frame.pack(fill=tk.X, pady=5)
        tk.Label(manual_frame, text="X:").grid(row=0, column=0, padx=5, pady=2); self.entry_x = tk.Entry(manual_frame, width=8); self.entry_x.grid(row=0, column=1)
        tk.Label(manual_frame, text="Y:").grid(row=0, column=2, padx=5, pady=2); self.entry_y = tk.Entry(manual_frame, width=8); self.entry_y.grid(row=0, column=3)
        tk.Label(manual_frame, text="Lebar:").grid(row=1, column=0, padx=5, pady=2); self.entry_w = tk.Entry(manual_frame, width=8); self.entry_w.grid(row=1, column=1)
        tk.Label(manual_frame, text="Tinggi:").grid(row=1, column=2, padx=5, pady=2); self.entry_h = tk.Entry(manual_frame, width=8); self.entry_h.grid(row=1, column=3)
        tk.Button(manual_frame, text="Buat Box Baru", command=self.create_box_from_input).grid(row=2, column=0, columnspan=2, pady=5, padx=5, sticky="ew")
        tk.Button(manual_frame, text="Update Box", command=self.update_box_from_input).grid(row=2, column=2, columnspan=2, pady=5, padx=5, sticky="ew")

        list_frame = tk.LabelFrame(control_frame, text="Daftar Bounding Box"); list_frame.pack(fill=tk.BOTH, expand=True, pady=5)
        self.box_listbox = tk.Listbox(list_frame); self.box_listbox.pack(side=tk.LEFT, fill=tk.BOTH, expand=True, pady=5, padx=5); self.box_listbox.bind('<<ListboxSelect>>', self.on_box_select_from_list)
        self.box_listbox.bind('<Double-Button-1>', self.on_listbox_double_click)

        box_actions_frame = tk.Frame(list_frame); box_actions_frame.pack(side=tk.LEFT, fill=tk.Y, padx=5)
        tk.Button(box_actions_frame, text="Hapus", command=self.delete_selected_box).pack(fill=tk.X, pady=2)
        tk.Button(box_actions_frame, text="Duplikat", command=self.duplicate_selected_box).pack(fill=tk.X, pady=2)
        tk.Button(box_actions_frame, text="Edit Label", command=self.edit_selected_box_label).pack(fill=tk.X, pady=2)

        guide_frame = tk.LabelFrame(control_frame, text="Penggaris (Guides)"); guide_frame.pack(fill=tk.X, pady=5)
        tk.Button(guide_frame, text="Tambah H", command=lambda: self.toggle_add_guide('h')).pack(side=tk.LEFT, expand=True, fill=tk.X, padx=2)
        tk.Button(guide_frame, text="Tambah V", command=lambda: self.toggle_add_guide('v')).pack(side=tk.LEFT, expand=True, fill=tk.X, padx=2)
        tk.Button(guide_frame, text="Hapus Guide", command=self.delete_selected_guide).pack(side=tk.LEFT, expand=True, fill=tk.X, padx=2)

        self.canvas = tk.Canvas(main_frame, bg="gray"); self.canvas.pack(fill=tk.BOTH, expand=True)
        self.canvas.bind("<ButtonPress-1>", self.on_mouse_press)
        self.canvas.bind("<B1-Motion>", self.on_mouse_drag)
        self.canvas.bind("<ButtonRelease-1>", self.on_mouse_release)
        self.canvas.bind("<Control-MouseWheel>", self.on_zoom)
        self.canvas.bind("<ButtonPress-2>", self.on_pan_start); self.canvas.bind("<B2-Motion>", self.on_pan_move); self.canvas.bind("<ButtonRelease-2>", self.on_pan_release)
        self.canvas.bind("<ButtonPress-3>", self.on_right_click)

        self.status_var = tk.StringVar(); self.status_var.set("Silakan muat gambar untuk memulai.")
        self.status_label = tk.Label(status_frame, textvariable=self.status_var, anchor=tk.W)
        self.status_label.pack(side=tk.LEFT, fill=tk.X, padx=5)

    def show_image(self):
        if not self.pil_image: return
        self.canvas.delete("all")
        w, h = self.pil_image.size
        new_w, new_h = int(w * self.zoom_factor), int(h * self.zoom_factor)
        try: resized_pil_image = self.pil_image.resize((new_w, new_h), Image.Resampling.LANCZOS)
        except AttributeError: resized_pil_image = self.pil_image.resize((new_w, new_h), Image.LANCZOS)
        self.tk_image = ImageTk.PhotoImage(resized_pil_image)
        self.canvas.create_image(self.offset_x, self.offset_y, anchor=tk.NW, image=self.tk_image)
        self.redraw_objects()

    def redraw_objects(self):
        for i, guide in enumerate(self.guides):
            color = self.config['COLOR_FOCUSED'] if i == self.selected_guide_index else self.config['COLOR_GUIDE']
            thickness = 2 if i == self.selected_guide_index else 1
            cx1, cy1, cx2, cy2, cx3, cy3, cx4, cy4 = self.get_guide_canvas_coords(guide)
            if guide['type'] == 'h': guide['id'] = self.canvas.create_line(cx1, cy1, cx2, cy2, fill=color, width=thickness)
            else: guide['id'] = self.canvas.create_line(cx3, cy3, cx4, cy4, fill=color, width=thickness)
        for i, box in enumerate(self.boxes):
            x1, y1, x2, y2 = box['coords']
            zx1, zy1 = self.image_to_canvas_coords(x1, y1); zx2, zy2 = self.image_to_canvas_coords(x2, y2)
            color = self.config['COLOR_FOCUSED'] if i == self.selected_box_index else self.config['COLOR_DEFAULT']
            box['id'] = self.canvas.create_rectangle(zx1, zy1, zx2, zy2, outline=color, width=2)
            text_id = self.canvas.create_text(zx1 + 3, zy1, text=box['label'], fill="white", anchor=tk.NW, font=("Arial", 8))
            text_bbox = self.canvas.bbox(text_id)
            if text_bbox:
                bg_rect_id = self.canvas.create_rectangle(text_bbox[0]-2, text_bbox[1], text_bbox[2]+2, text_bbox[3], fill=color, outline="")
                self.canvas.lift(text_id, bg_rect_id)
            box['text_id'] = text_id
            box['text_bg_id'] = bg_rect_id if text_bbox else None

    def get_guide_canvas_coords(self, guide):
        pos = guide['pos']; canvas_width, canvas_height = self.canvas.winfo_width(), self.canvas.winfo_height()
        cx1, cy1 = self.image_to_canvas_coords(0, pos); cx2, cy2 = self.image_to_canvas_coords(self.pil_image.width, pos)
        cx3, cy3 = self.image_to_canvas_coords(pos, 0); cx4, cy4 = self.image_to_canvas_coords(pos, self.pil_image.height)
        return 0, cy1, canvas_width, cy2, cx3, 0, cx4, canvas_height

    def on_zoom(self, event):
        if not self.pil_image: return
        mouse_x, mouse_y = self.canvas.canvasx(event.x), self.canvas.canvasy(event.y)
        img_x, img_y = self.canvas_to_image_coords(mouse_x, mouse_y)
        factor = 1.1 if event.delta > 0 else 0.9
        self.zoom_factor *= factor
        new_mouse_x, new_mouse_y = self.image_to_canvas_coords(img_x, img_y)
        self.offset_x += mouse_x - new_mouse_x; self.offset_y += mouse_y - new_mouse_y
        self.show_image()

    def on_pan_start(self, event):
        if not self.pil_image: return
        self.mode = 'pan'; self.canvas.config(cursor="fleur"); self.drag_start_pos = (event.x, event.y)

    def on_pan_move(self, event):
        if self.mode != 'pan': return
        dx = event.x - self.drag_start_pos[0]; dy = event.y - self.drag_start_pos[1]
        self.offset_x += dx; self.offset_y += dy
        self.drag_start_pos = (event.x, event.y); self.show_image()

    def on_pan_release(self, event):
        self.mode = None; self.canvas.config(cursor="cross")

    def reset_zoom(self, event):
        if not self.pil_image: return
        self.zoom_factor = 1.0; self.offset_x = 0; self.offset_y = 0
        self.show_image()

    def canvas_to_image_coords(self, canvas_x, canvas_y):
        return (self.canvas.canvasx(canvas_x) - self.offset_x) / self.zoom_factor, (self.canvas.canvasy(canvas_y) - self.offset_y) / self.zoom_factor

    def image_to_canvas_coords(self, img_x, img_y):
        return img_x * self.zoom_factor + self.offset_x, img_y * self.zoom_factor + self.offset_y

    def on_mouse_press(self, event):
        if not self.pil_image or self.mode == 'pan': return
        canvas_x, canvas_y = self.canvas.canvasx(event.x), self.canvas.canvasy(event.y)
        img_x, img_y = self.canvas_to_image_coords(canvas_x, canvas_y)
        if self.mode in ['add_guide_h', 'add_guide_v']: self._add_guide(img_y if self.mode == 'add_guide_h' else img_x); return

        self.drag_start_pos = (img_x, img_y)
        if self.edit_mode.get() == "edit":
            guide_index = self._find_guide_at_coords(canvas_x, canvas_y)
            box_index = self._find_box_at_coords(img_x, img_y, expanded=True)
            if guide_index is not None:
                self.mode = 'move_guide'; self.focus_on_guide(guide_index); self.canvas.config(cursor="sb_v_double_arrow" if self.guides[guide_index]['type'] == 'h' else "sb_h_double_arrow")
            elif box_index is not None:
                self.mode = 'move'; self.focus_on_box(box_index); self.canvas.config(cursor="fleur")
            else: self.clear_all_focus()
        elif self.edit_mode.get() == "create":
            self.mode = 'draw'; self.clear_all_focus()
            self.current_rect_id = self.canvas.create_rectangle(canvas_x, canvas_y, canvas_x, canvas_y, outline=self.config['COLOR_DEFAULT'], width=2)
            self.info_text_id = self.canvas.create_text(canvas_x + 10, canvas_y, anchor=tk.NW, fill=self.config['COLOR_INFO_TEXT'], text="")
            self.canvas.lift(self.current_rect_id); self.canvas.lift(self.info_text_id)

    def on_mouse_drag(self, event):
        if not self.drag_start_pos: return
        canvas_x, canvas_y = self.canvas.canvasx(event.x), self.canvas.canvasy(event.y)
        img_x, img_y = self.canvas_to_image_coords(canvas_x, canvas_y)
        if self.mode == 'draw': self._handle_draw_drag(img_x, img_y, canvas_x, canvas_y)
        elif self.mode == 'move': self._handle_move_drag(img_x, img_y)
        elif self.mode == 'move_guide': self.handle_move_guide(img_x, img_y)

    def on_mouse_release(self, event):
        if self.mode in ['draw', 'move', 'move_guide']:
            if self.mode == 'draw': img_x, img_y = self.canvas_to_image_coords(event.x, event.y); self._handle_draw_release(img_x, img_y)
            elif self.mode == 'move': self._handle_move_release(event)
            elif self.mode == 'move_guide': self._handle_move_guide_release()
            if self.info_text_id: self.canvas.delete(self.info_text_id); self.info_text_id = None
            if self.current_rect_id: self.canvas.delete(self.current_rect_id); self.current_rect_id = None
            self.mode = None; self.canvas.config(cursor="cross")

    def on_right_click(self, event):
        canvas_x, canvas_y = self.canvas.canvasx(event.x), self.canvas.canvasy(event.y)
        guide_index = self._find_guide_at_coords(canvas_x, canvas_y)
        if guide_index is not None: self.delete_guide(guide_index)
        else: self.reset_zoom(event)

    def _find_box_at_coords(self, img_x, img_y, expanded=False):
        margin = self.config['HITBOX_MARGIN'] / self.zoom_factor if expanded else 0
        for i, box in reversed(list(enumerate(self.boxes))):
            x1, y1, x2, y2 = box['coords']
            if expanded:
                outer_x1, outer_y1, outer_x2, outer_y2 = x1 - margin, y1 - margin, x2 + margin, y2 + margin
                inner_x1, inner_y1, inner_x2, inner_y2 = x1 + margin, y1 + margin, x2 - margin, y2 - margin
                if (outer_x1 <= img_x <= outer_x2 and outer_y1 <= img_y <= outer_y2) and not (inner_x1 <= img_x <= inner_x2 and inner_y1 <= img_y <= inner_y2): return i
            elif x1 <= img_x <= x2 and y1 <= img_y <= y2: return i
        return None

    def _find_guide_at_coords(self, canvas_x, canvas_y):
        tolerance = 5
        for i, guide in enumerate(self.guides):
            pos_c = guide['pos'] * self.zoom_factor + (self.offset_y if guide['type'] == 'h' else self.offset_x)
            if guide['type'] == 'h' and abs(canvas_y - pos_c) <= tolerance: return i
            if guide['type'] == 'v' and abs(canvas_x - pos_c) <= tolerance: return i
        return None

    def toggle_add_guide(self, guide_type):
        self.mode = f'add_guide_{guide_type}'; self.canvas.config(cursor="tcross")
        self.status_var.set(f"Klik pada kanvas untuk menempatkan guide {'horizontal' if guide_type == 'h' else 'vertikal'}")

    def _handle_draw_drag(self, img_x, img_y, canvas_x, canvas_y):
        if self.current_rect_id is None: return
        start_img_x, start_img_y = self.drag_start_pos
        zx1, zy1 = self.image_to_canvas_coords(start_img_x, start_img_y)
        zx2, zy2 = self.image_to_canvas_coords(img_x, img_y)
        self.canvas.coords(self.current_rect_id, zx1, zy1, zx2, zy2)
        w, h = abs(img_x - start_img_x), abs(img_y - start_img_y); info_text = f"({int(min(start_img_x, img_x))}, {int(min(start_img_y, img_y))})\n{int(w)}x{int(h)}"
        if self.info_text_id: self.canvas.coords(self.info_text_id, canvas_x + 10, canvas_y); self.canvas.itemconfig(self.info_text_id, text=info_text)
        self.status_var.set(f"Menggambar... Ukuran: {int(w)}x{int(h)}")

    def _handle_move_drag(self, img_x, img_y):
        if self.selected_box_index is None or not self.drag_start_pos: return
        dx, dy = img_x - self.drag_start_pos[0], img_y - self.drag_start_pos[1]
        box = self.boxes[self.selected_box_index]; orig_coords = box['orig_coords_on_drag']
        new_coords = (orig_coords[0] + dx, orig_coords[1] + dy, orig_coords[2] + dx, orig_coords[3] + dy)
        zx1, zy1 = self.image_to_canvas_coords(new_coords[0], new_coords[1]); zx2, zy2 = self.image_to_canvas_coords(new_coords[2], new_coords[3])
        # Gunakan canvas.coords untuk live preview, bukan redraw total
        if box.get('id'): self.canvas.coords(box['id'], zx1, zy1, zx2, zy2)
        if box.get('text_id'):
            text_bbox = self.canvas.bbox(box['text_id'])
            if text_bbox:
                bg_rect_id = box.get('text_bg_id')
                self.canvas.coords(box['text_id'], zx1 + 3, zy1)
                new_text_bbox = self.canvas.bbox(box['text_id'])
                if bg_rect_id and new_text_bbox:
                    self.canvas.coords(bg_rect_id, new_text_bbox[0]-2, new_text_bbox[1], new_text_bbox[2]+2, new_text_bbox[3])
        self.status_var.set(f"Memindahkan '{box['label']}' ke ({int(new_coords[0])},{int(new_coords[1])})")
        self._populate_entries_from_coords(new_coords)

    def handle_move_guide(self, img_x, img_y):
        if self.selected_guide_index is None: return
        guide = self.guides[self.selected_guide_index]
        guide['pos'] = img_y if guide['type'] == 'h' else img_x
        cx1, cy1, cx2, cy2, cx3, cy3, cx4, cy4 = self.get_guide_canvas_coords(guide)
        if guide.get('id'):
            if guide['type'] == 'h': self.canvas.coords(guide['id'], cx1, cy1, cx2, cy2)
            else: self.canvas.coords(guide['id'], cx3, cy3, cx4, cy4)
        self.status_var.set(f"Memindahkan guide ke posisi {int(guide['pos'])}")

    def _add_box(self, coords):
        label = simpledialog.askstring("Input Label", "Masukkan label untuk box ini:", parent=self.root)
        if not label: self.show_image(); return
        self.boxes.append({'label': label, 'coords': coords, 'id': None, 'text_id': None, 'text_bg_id': None})
        self.show_image() # Redraw untuk menampilkan box baru
        self.focus_on_box(len(self.boxes) - 1)
        self.update_box_list()

    def _handle_draw_release(self, img_x, img_y):
        if self.drag_start_pos is None: return
        x1, y1 = min(self.drag_start_pos[0], img_x), min(self.drag_start_pos[1], img_y)
        x2, y2 = max(self.drag_start_pos[0], img_x), max(self.drag_start_pos[1], img_y)
        if abs(x1 - x2) >= 5 and abs(y1 - y2) >= 5: self._add_box((int(x1), int(y1), int(x2), int(y2)))
        self.drag_start_pos = None

    def _handle_move_release(self, event):
        if self.selected_box_index is None or not self.drag_start_pos: return
        box = self.boxes[self.selected_box_index]
        final_img_x, final_img_y = self.canvas_to_image_coords(event.x, event.y)
        dx, dy = final_img_x - self.drag_start_pos[0], final_img_y - self.drag_start_pos[1]
        orig_coords = box['orig_coords_on_drag']
        final_coords = (orig_coords[0] + dx, orig_coords[1] + dy, orig_coords[2] + dx, orig_coords[3] + dy)
        box['coords'] = tuple(int(c) for c in final_coords)
        del box['orig_coords_on_drag']
        self.update_box_list(); self.status_var.set(f"Box '{box['label']}' dipindahkan."); self.drag_start_pos = None
        self.show_image()

    def _handle_move_guide_release(self):
        if self.selected_guide_index is None: return
        # PERBAIKAN: Jangan clear focus, biarkan guide tetap terpilih.
        self.status_var.set("Guide dipindahkan.")
        self.show_image()

    def _add_guide(self, pos):
        guide_type = 'h' if self.mode == 'add_guide_h' else 'v'
        self.guides.append({'type': guide_type, 'pos': pos, 'id': None})
        self.mode = None; self.canvas.config(cursor="cross"); self.show_image(); self.status_var.set("Guide ditambahkan.")

    def focus_on_guide(self, index):
        self.clear_all_focus(clear_guides=False)
        self.selected_guide_index = index
        self.status_var.set(f"Guide {index + 1} dipilih."); self.show_image()

    def delete_guide(self, index):
        if messagebox.askyesno("Konfirmasi", "Anda yakin ingin menghapus guide ini?"):
            self.guides.pop(index); self.clear_all_focus()

    def delete_selected_guide(self):
        if self.selected_guide_index is not None: self.delete_guide(self.selected_guide_index)
        else: messagebox.showwarning("Peringatan", "Pilih sebuah guide terlebih dahulu dengan mengkliknya di kanvas.")

    def focus_on_box(self, index):
        self.clear_all_focus(clear_boxes=False); self.selected_box_index = index; box = self.boxes[index]
        box['orig_coords_on_drag'] = box['coords']; self._populate_entries_from_coords(box['coords']); self.box_listbox.selection_clear(0, tk.END)
        self.box_listbox.selection_set(index); self.status_var.set(f"Box '{box['label']}' dipilih."); self.show_image()

    def clear_all_focus(self, clear_boxes=True, clear_guides=True):
        changed = False
        if clear_boxes and self.selected_box_index is not None:
            self.selected_box_index = None; changed = True
        if clear_guides and self.selected_guide_index is not None:
            self.selected_guide_index = None; changed = True

        if changed:
            self.box_listbox.selection_clear(0, tk.END); self._clear_entries()
            if self.pil_image: self.show_image()

    def on_box_select_from_list(self, event):
        if not self.box_listbox.curselection(): return
        self.focus_on_box(self.box_listbox.curselection()[0])

    def on_listbox_double_click(self, event):
        if not self.box_listbox.curselection(): return
        self.edit_selected_box_label()

    def edit_selected_box_label(self):
        if self.selected_box_index is None: messagebox.showwarning("Peringatan", "Pilih sebuah box untuk diedit labelnya."); return
        box = self.boxes[self.selected_box_index]
        new_label = simpledialog.askstring("Edit Label", "Masukkan label baru:", initialvalue=box['label'], parent=self.root)
        if new_label and new_label != box['label']:
            box['label'] = new_label; self.update_box_list(); self.show_image(); self.status_var.set(f"Label diubah menjadi '{new_label}'")

    def duplicate_selected_box(self):
        if self.selected_box_index is None: messagebox.showwarning("Peringatan", "Pilih sebuah box untuk diduplikasi."); return
        original_box = self.boxes[self.selected_box_index]; x1, y1, x2, y2 = original_box['coords']
        new_coords = (x1 + 10, y1, x2 + 10, y2)
        # PERBAIKAN: Langsung panggil _add_box yang sudah berisi dialog
        self._add_box(new_coords)

    def change_color(self, key):
        new_color = colorchooser.askcolor(title=f"Pilih Warna untuk {key}", initialcolor=self.config[key])
        if new_color and new_color[1]: self.config[key] = new_color[1]
        if self.pil_image: self.show_image()
    def _clear_all(self):
        self.canvas.delete("all"); self.boxes = []; self.guides = []
        self.box_listbox.delete(0, tk.END); self._clear_entries()
        self.selected_box_index = None; self.selected_guide_index = None
        self.image_path = None; self.pil_image = None; self.tk_image = None
        self.zoom_factor = 1.0; self.offset_x = 0; self.offset_y = 0
        self.status_var.set("Silakan muat gambar untuk memulai.")
    def load_image(self, path=None):
        if not path:
            filetypes = [("All Supported Images", "*.jpg *.jpeg *.png *.bmp *.webp"),("WEBP Files", "*.webp"),("All files", "*.*")]
            path = filedialog.askopenfilename(filetypes=filetypes)
        if not path: return
        self._clear_all(); self.image_path = path; self.pil_image = Image.open(path); self.show_image(); self.status_var.set(f"Gambar dimuat: {os.path.basename(self.image_path)}")
    def create_box_from_input(self):
        if not self.pil_image: return
        try: x, y, w, h = int(self.entry_x.get()), int(self.entry_y.get()), int(self.entry_w.get()), int(self.entry_h.get())
        except ValueError: messagebox.showerror("Error", "Input harus berupa angka."); return
        self._add_box((x, y, x + w, y + h))
    def update_box_from_input(self):
        if self.selected_box_index is None: messagebox.showwarning("Peringatan", "Pilih box yang ingin diupdate."); return
        try: x, y, w, h = int(self.entry_x.get()), int(self.entry_y.get()), int(self.entry_w.get()), int(self.entry_h.get())
        except ValueError: messagebox.showerror("Error", "Input harus berupa angka."); return
        new_coords = (x, y, x + w, y + h); self.boxes[self.selected_box_index]['coords'] = new_coords
        self.show_image(); self.update_box_list(); self.status_var.set(f"Box '{self.boxes[self.selected_box_index]['label']}' diupdate.")
    def _populate_entries_from_coords(self, coords):
        self._clear_entries(); x1, y1, x2, y2 = map(int, coords)
        self.entry_x.insert(0, x1); self.entry_y.insert(0, y1); self.entry_w.insert(0, x2 - x1); self.entry_h.insert(0, y2 - y1)
    def _clear_entries(self):
        self.entry_x.delete(0, tk.END); self.entry_y.delete(0, tk.END); self.entry_w.delete(0, tk.END); self.entry_h.delete(0, tk.END)
    def update_box_list(self):
        self.box_listbox.delete(0, tk.END)
        for box in self.boxes:
            coords, label = box['coords'], box['label']; w, h = coords[2] - coords[0], coords[3] - coords[1]
            self.box_listbox.insert(tk.END, f"{label}: ({int(coords[0])},{int(coords[1])}) {int(w)}x{int(h)}")
    def delete_selected_box(self):
        if self.selected_box_index is None: messagebox.showwarning("Peringatan", "Pilih sebuah box untuk dihapus."); return
        self.boxes.pop(self.selected_box_index); self.clear_all_focus(); self.update_box_list()
    def save_project(self):
        if not self.image_path: return
        filepath = filedialog.asksaveasfilename(defaultextension=".sux", filetypes=[("SUX Project File", "*.sux")], title="Simpan Proyek")
        if not filepath: return
        boxes_to_save = [{'label': b['label'], 'coords': b['coords']} for b in self.boxes]
        guides_to_save = [{'type': g['type'], 'pos': g['pos']} for g in self.guides]
        project_data = {'image_path': self.image_path, 'boxes': boxes_to_save, 'guides': guides_to_save}
        with open(filepath, 'w') as f: json.dump(project_data, f, indent=4)
        self.status_var.set(f"Proyek disimpan di {os.path.basename(filepath)}")
    def load_project(self):
        filepath = filedialog.askopenfilename(filetypes=[("SUX Project File", "*.sux")], title="Muat Proyek")
        if not filepath: return
        with open(filepath, 'r') as f: project_data = json.load(f)
        self.load_image(path=project_data['image_path'])
        if 'boxes' in project_data:
            for box_data in project_data['boxes']: self.boxes.append({'label': box_data['label'], 'coords': tuple(box_data['coords'])})
        if 'guides' in project_data:
            for guide_data in project_data['guides']: self.guides.append({'type': guide_data['type'], 'pos': guide_data['pos']})
        self.show_image(); self.update_box_list(); self.status_var.set(f"Proyek {os.path.basename(filepath)} dimuat.")
    def export_boxes(self):
        if not self.boxes: return
        format_choice = self._ask_format()
        if not format_choice: return
        output_dir = filedialog.askdirectory(title="Pilih Folder Induk untuk Menyimpan Hasil")
        if not output_dir: return
        base_filename = os.path.splitext(os.path.basename(self.image_path))[0]
        try:
            count = 0;
            for box in self.boxes:
                label, coords = box['label'], tuple(map(int, box['coords']))
                label_dir = os.path.join(output_dir, label); os.makedirs(label_dir, exist_ok=True)
                cropped_image = self.pil_image.crop(coords); ext = "jpg" if format_choice == "JPG" else "png"
                output_filename = f"{label}_{base_filename}.{ext}"; save_path = os.path.join(label_dir, output_filename)
                if ext == "jpg": cropped_image.convert("RGB").save(save_path)
                else: cropped_image.save(save_path)
                count += 1
            messagebox.showinfo("Sukses", f"{count} gambar berhasil diexport.")
        except Exception as e: messagebox.showerror("Error", f"Terjadi kesalahan saat export: {e}")
    def _ask_format(self):
        dialog = Toplevel(self.root); dialog.title("Pilih Format"); dialog.geometry("250x100"); dialog.transient(self.root); dialog.grab_set()
        result = tk.StringVar(); tk.Label(dialog, text="Pilih format gambar untuk export:").pack(pady=10)
        frame = tk.Frame(dialog); frame.pack()
        def set_fmt(fmt): result.set(fmt); dialog.destroy()
        tk.Button(frame, text="JPG", width=10, command=lambda: set_fmt("JPG")).pack(side=tk.LEFT, padx=10)
        tk.Button(frame, text="PNG", width=10, command=lambda: set_fmt("PNG")).pack(side=tk.LEFT, padx=10)
        self.root.wait_window(dialog); return result.get()

if __name__ == "__main__":
    root = tk.Tk()
    app = BoundingBoxApp(root)
    root.mainloop()