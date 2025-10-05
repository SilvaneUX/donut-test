# Admin CMS Features

## Overview
The JoVan website now includes a comprehensive Content Management System (CMS) that allows administrators to customize the entire website from the admin dashboard.

## Features

### 1. Dark/Light Mode Toggle
- Toggle button in the navbar (moon/sun icon)
- Theme preference is saved in localStorage
- Persists across sessions and page refreshes
- Automatically applies dark mode styles to all components

### 2. Site Settings Management
Access via: Admin Dashboard → Site Settings

#### Theme Colors
- Customize primary color (navbar, buttons)
- Customize secondary color (gradients, accents)
- Color picker with hex code input
- Changes reflect immediately after saving

#### Navbar Settings
- Edit site title
- Upload or link to logo image
- Toggle logo visibility
- Choose between image upload or external URL

#### Hero Section Settings
- Customize hero title
- Edit hero subtitle
- Option to use background image
- Upload image or use external URL
- Falls back to gradient if no image

#### About Us Content
- Edit company description
- Customize vision statement
- Update mission statement

#### About Us Custom Sections
- Add unlimited custom sections to About Us page
- Each section includes:
  - Title
  - Content (supports multi-line text)
  - Optional emoji icon
- Delete sections when no longer needed
- Sections appear after the default "Why Choose Us" section

#### Contact Information
- WhatsApp number
- Email address
- Phone number
- Physical address

#### Custom Contact Information
- Add custom contact info boxes
- Each box includes:
  - Title
  - Content
  - Optional emoji icon
  - Optional clickable link
- Delete boxes when no longer needed
- Boxes appear in the contact information section

### 3. Image Upload
Two methods available for all image fields:
1. **Upload**: Upload images to `/public/uploads/` directory
2. **URL**: Use external image URLs

### 4. Product Management with Image Upload
Enhanced product form includes:
- Toggle between URL and upload for product images
- Image preview after upload
- All product fields easily editable

### 5. Session Persistence
- Admin sessions are automatically saved via NextAuth
- Resumable from any page
- Secure authentication

### 6. Modern UI Updates
- Rounded corners (rounded-xl, rounded-2xl) for cards and buttons
- Enhanced shadow effects
- Smooth transitions
- Responsive design maintained

## Usage

### Accessing Admin Panel
1. Navigate to `/admin/login`
2. Default credentials:
   - Email: `admin@jovan.com`
   - Password: `admin123`
3. Click "Sign In"

### Managing Site Settings
1. From Admin Dashboard, click "Site Settings"
2. Use tabs to navigate between settings sections
3. Make desired changes
4. Click "Save Changes" button

### Uploading Images
1. In any image field, click "Upload" button
2. Click "Choose File" and select image
3. Wait for upload to complete
4. Image URL will be automatically filled

### Managing Products
1. From Admin Dashboard, view products table
2. Click "Add Product" to add new
3. Click "Edit" to modify existing products
4. Use image upload or URL for product images
5. Click "Delete" to remove products

## Technical Details

### File Structure
```
contexts/
├── ThemeContext.tsx       # Dark/light mode management
└── SettingsContext.tsx    # Site settings management

app/api/
├── settings/route.ts      # Settings CRUD operations
└── upload/route.ts        # Image upload handling

data/
├── settings.json          # Site settings storage
├── products.json          # Products database
└── users.json            # User credentials

public/uploads/           # Uploaded images directory
```

### Environment Variables
Required in `.env.local`:
```
NEXTAUTH_SECRET=your-secret-key
NEXTAUTH_URL=http://localhost:3000
```

## Development

### Building
```bash
npm run build
```

### Running Development Server
```bash
npm run dev
```

### Production Deployment
1. Update `NEXTAUTH_SECRET` with secure random string
2. Change default admin credentials
3. Consider migrating from JSON to database
4. Configure proper image storage (S3, Cloudinary, etc.)
5. Enable SSL/HTTPS

## Security Notes
- Change default admin credentials before production
- Set secure NEXTAUTH_SECRET
- Uploaded images are stored locally in `/public/uploads/`
- Consider implementing image size limits and validation
- Add file type restrictions for uploads

## Browser Support
- Modern browsers with localStorage support
- JavaScript enabled required
- CSS Grid and Flexbox support needed
