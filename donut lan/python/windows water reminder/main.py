import pystray
import PIL.Image
import time
from winotify import Notification, audio
import threading

image = PIL.Image.open("water.png")
run = False

def on_click(icon, item):
    global run
    item = str(item)

    if item == "1 hour":
        run = True
        reminder(1)
    elif item == "2 hours":
        run = True
        reminder(2)
    elif item == "4 hours":
        run = True
        reminder(4)
    elif item == "8 hours":
        run = True
        reminder(8)
    elif item == "Exit":
        icon.stop()

icon = pystray.Icon("Drink Reminder", image, menu=pystray.Menu(
    pystray.MenuItem("Start", pystray.Menu(
        pystray.MenuItem("1 hour", on_click),
        pystray.MenuItem("2 hours", on_click),
        pystray.MenuItem("4 hours", on_click),
        pystray.MenuItem("8 hours", on_click)
    )),
    pystray.MenuItem("Exit", on_click)
))

def reminder(count):
    global run
    start = time.time()
    count *= 3
    counter = 0

    while run:
        if (time.time() - start) >= 1200:
            toast = Notification(
                app_id="MINUM!",
                title="Waktunya minum!",
                msg="Ayo minum sebentar, sudah 20 menit kamu duduk!",
                duration="long"
            )

            toast.set_audio(audio.LoopingAlarm, loop=True)

            toast.add_actions(label="Oke udah!")

            toast.show()
            print("Hai")

            # reset timer
            start = time.time()

            if counter == count:
                break

            counter += 1
        else:
            continue

def main():
    icon.run()

if __name__ == '__main__':
    main()