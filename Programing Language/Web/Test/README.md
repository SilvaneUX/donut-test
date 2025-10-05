# JoVan - Export & Import Commodities Website

A modern, fully responsive Next.js website for promoting export and import of local commodities. Built with Next.js 15, TypeScript, Tailwind CSS, and NextAuth for authentication.

## Features

### Customer-Facing Features
- **Home Page**: Attractive landing page with hero section, features, and featured products
- **Product Catalog**: Browse all available products with detailed information
- **Product Cards**: Each product card includes:
  - Product image, name, description, and category
  - WhatsApp contact button for direct inquiries
  - Responsive design
- **About Us**: Company information, vision, mission, why choose us, and custom sections
- **Contact Page**: Multiple contact options including WhatsApp, email, phone, address, and custom info boxes
- **Fully Responsive**: Works perfectly on mobile, tablet, and desktop devices
- **Dark/Light Mode**: Toggle between light and dark themes with automatic persistence

### Admin Features
- **Secure Login**: Protected admin area with email/password authentication
- **Dashboard**: Manage all products in one place
- **Product Management**:
  - Add new products
  - Edit existing products
  - Delete products
  - View all products in a table format
- **Site Settings Management**:
  - **Theme Customization**: Customize primary and secondary colors that apply throughout the site
  - **Navbar Settings**: Edit site title, upload logo, and toggle logo visibility
  - **Hero Section**: Customize hero title, subtitle, and background image
  - **About Us Content**: Edit description, vision, and mission statements
  - **Contact Information**: Manage WhatsApp, email, phone, and address
  - **Custom Sections**: Add/edit/delete custom sections on About Us page
  - **Custom Contact Info**: Add/edit/delete custom contact information boxes
- **Dark/Light Mode**: Full theme support with toggle in navbar
- **Image Upload**: Upload images for logos, hero backgrounds, and products

## Tech Stack

- **Framework**: Next.js 15 with App Router
- **Language**: TypeScript
- **Styling**: Tailwind CSS 4
- **Authentication**: NextAuth.js v5 (beta)
- **Icons**: React Icons
- **Password Hashing**: bcryptjs

## Getting Started

### Prerequisites

- Node.js 18+ installed
- npm or yarn package manager

### Installation

1. Clone the repository:
```bash
git clone https://github.com/SilvaneUX/JoVan.git
cd JoVan
```

2. Install dependencies:
```bash
npm install
```

3. Set up environment variables:
Create a `.env.local` file in the root directory:
```env
NEXTAUTH_URL=http://localhost:3000
NEXTAUTH_SECRET=your-secret-key-change-this-in-production
```

4. Run the development server:
```bash
npm run dev
```

5. Open [http://localhost:3000](http://localhost:3000) in your browser

### Building for Production

```bash
npm run build
npm start
```

## Default Admin Credentials

- **Email**: admin@jovan.com
- **Password**: admin123

⚠️ **Important**: Change these credentials in production by updating the `data/users.json` file with a new bcrypt-hashed password.

## Project Structure

```
JoVan/
├── app/                      # Next.js App Router pages
│   ├── about/               # About Us page
│   ├── admin/               # Admin area
│   │   ├── dashboard/       # Admin dashboard
│   │   ├── login/           # Admin login page
│   │   └── settings/        # Site settings management
│   ├── api/                # API routes
│   │   ├── auth/           # NextAuth endpoints
│   │   ├── products/       # Product CRUD APIs
│   │   ├── settings/       # Settings API
│   │   └── upload/         # Image upload API
│   ├── contact/            # Contact page
│   ├── products/           # Products listing page
│   ├── layout.tsx          # Root layout
│   └── page.tsx            # Home page
├── components/              # React components
│   ├── AuthProvider.tsx    # NextAuth session provider
│   ├── Footer.tsx          # Footer component
│   ├── HeroSection.tsx     # Hero section component
│   ├── HomeContent.tsx     # Home page client content
│   ├── Navbar.tsx          # Navigation bar
│   └── ProductCard.tsx     # Product card component
├── contexts/                # React contexts
│   ├── SettingsContext.tsx # Site settings management
│   └── ThemeContext.tsx    # Dark/light mode management
├── data/                    # Data storage
│   ├── products.json       # Products database
│   ├── settings.json       # Site settings storage
│   └── users.json          # Users database
├── lib/                     # Utility functions
│   ├── auth.ts             # NextAuth configuration
│   ├── products.ts         # Product CRUD functions
│   └── users.ts            # User functions
├── types/                   # TypeScript types
│   ├── index.ts            # App types
│   └── next-auth.d.ts      # NextAuth type extensions
└── public/                  # Static assets
    └── uploads/            # Uploaded images directory
```

## Key Features Explained

### WhatsApp Integration
Each product card includes a "Contact via WhatsApp" button that:
- Opens WhatsApp with a pre-filled message
- Includes the product name in the message
- Works on both mobile and desktop

### Admin Dashboard
- Protected route requiring authentication
- Add, edit, and delete products
- Comprehensive site settings management
- Theme customization (colors that apply site-wide)
- Content management for About Us and Contact pages
- Custom section creation for dynamic content
- Dark/light mode support
- Real-time preview of changes

### Responsive Design
- Mobile-first approach using Tailwind CSS
- Hamburger menu on mobile devices
- Flexible grid layouts
- Optimized for all screen sizes

## Customization

### Using Admin Dashboard (Recommended)

The easiest way to customize the website is through the admin dashboard:

1. **Login**: Navigate to `/admin/login` and use the default credentials
2. **Site Settings**: Click "Site Settings" from the dashboard
3. **Available Settings**:
   - **Theme Colors**: Customize primary and secondary colors
   - **Navbar**: Change site title, upload logo
   - **Hero Section**: Edit title, subtitle, and background image
   - **About Us**: Modify description, vision, and mission
   - **About Sections**: Add custom sections with title, content, and icon
   - **Contact Info**: Update WhatsApp, email, phone, and address
   - **Custom Contact**: Add additional contact information boxes

### Adding Custom Sections

#### About Us Page
1. Go to Admin Dashboard → Site Settings → About Sections
2. Click "Add New Section"
3. Enter title, content, and optional emoji icon
4. Click "Save Changes"

#### Contact Page
1. Go to Admin Dashboard → Site Settings → Custom Contact
2. Click "Add New Info Box"
3. Enter title, content, emoji icon, and optional link
4. Click "Save Changes"

### Manual Customization

#### Adding Products
Products are stored in `data/products.json`. You can either:
1. Use the admin dashboard (recommended)
2. Manually edit the JSON file

#### Changing Site Settings
All site settings are stored in `data/settings.json`:
```json
{
  "theme": {
    "primaryColor": "#2563eb",
    "secondaryColor": "#1e40af"
  },
  "navbar": {
    "title": "JoVan",
    "logo": "",
    "showLogo": false
  },
  ...
}
```

### Styling
The project uses Tailwind CSS. You can customize:
- Colors in component files
- Global styles in `app/globals.css`
- Tailwind configuration (if needed)

## Security Notes

1. **Change default admin credentials** before deploying to production
2. **Update NEXTAUTH_SECRET** to a strong random string
3. The current implementation uses JSON files for simplicity - consider using a database for production
4. Enable HTTPS in production

## Future Enhancements

Potential improvements for production:
- Database integration (PostgreSQL, MongoDB, etc.)
- Advanced image management
- Email notifications
- Order management system
- Multiple admin users with roles
- Product categories filtering
- Search functionality
- Analytics dashboard
- Rich text editor for content
- Section reordering with drag-and-drop
- Export/import settings

## Recent Updates

See [UPDATE.md](UPDATE.md) for detailed changelog of recent updates including:
- Dark/light mode fixes
- Dynamic theme color application
- Custom section management
- Enhanced admin features

## Documentation

- **[ADMIN_CMS_FEATURES.md](ADMIN_CMS_FEATURES.md)**: Complete admin features documentation
- **[IMPLEMENTATION.md](IMPLEMENTATION.md)**: Implementation details
- **[UPDATE.md](UPDATE.md)**: Detailed changelog and update notes

## License

This project is open source and available under the MIT License.

## Support

For issues or questions, please create an issue in the GitHub repository.

---

Built with ❤️ for local commodity export and import businesses
