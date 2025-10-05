'use client';

import Link from 'next/link';
import { FaFacebook, FaInstagram, FaTwitter, FaLinkedin } from 'react-icons/fa';
import { useSettings } from '@/contexts/SettingsContext';
import { useTheme } from '@/contexts/ThemeContext';
import { getFontColor } from '@/lib/colorUtils';

export default function Footer() {
  const { settings } = useSettings();
  const { theme } = useTheme();

  const primaryColor = settings?.theme.primaryColor || '#2563eb';
  const fontColorMode = settings?.theme.fontColorMode || 'auto';
  const manualFontColor = settings?.theme.fontColor;
  
  // Get font color based on settings
  const footerBgColor = theme === 'dark' ? '#1e293b' : primaryColor;
  const fontColor = getFontColor(footerBgColor, fontColorMode, manualFontColor);

  return (
    <footer className="mt-auto" style={{ backgroundColor: footerBgColor, color: fontColor }}>
      <div className="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8 py-12">
        <div className="grid grid-cols-1 md:grid-cols-3 gap-8">
          {/* Company Info */}
          <div>
            <h3 className="text-xl font-bold mb-4" style={{ color: fontColor }}>
              {settings?.navbar.title || 'JoVan'}
            </h3>
            <p style={{ opacity: 0.85 }}>
              Your trusted partner for export and import of local commodities.
            </p>
          </div>

          {/* Quick Links */}
          <div>
            <h3 className="text-xl font-bold mb-4" style={{ color: fontColor }}>Quick Links</h3>
            <ul className="space-y-2">
              <li>
                <Link href="/" className="hover:opacity-80 transition" style={{ color: fontColor, opacity: 0.85 }}>
                  Home
                </Link>
              </li>
              <li>
                <Link href="/products" className="hover:opacity-80 transition" style={{ color: fontColor, opacity: 0.85 }}>
                  Products
                </Link>
              </li>
              <li>
                <Link href="/about" className="hover:opacity-80 transition" style={{ color: fontColor, opacity: 0.85 }}>
                  About Us
                </Link>
              </li>
              <li>
                <Link href="/contact" className="hover:opacity-80 transition" style={{ color: fontColor, opacity: 0.85 }}>
                  Contact
                </Link>
              </li>
            </ul>
          </div>

          {/* Social Media */}
          <div>
            <h3 className="text-xl font-bold mb-4" style={{ color: fontColor }}>Follow Us</h3>
            <div className="flex space-x-4">
              <a
                href="https://facebook.com"
                target="_blank"
                rel="noopener noreferrer"
                className="text-2xl hover:opacity-80 transition"
                style={{ color: fontColor }}
              >
                <FaFacebook />
              </a>
              <a
                href="https://instagram.com"
                target="_blank"
                rel="noopener noreferrer"
                className="text-2xl hover:opacity-80 transition"
                style={{ color: fontColor }}
              >
                <FaInstagram />
              </a>
              <a
                href="https://twitter.com"
                target="_blank"
                rel="noopener noreferrer"
                className="text-2xl hover:opacity-80 transition"
                style={{ color: fontColor }}
              >
                <FaTwitter />
              </a>
              <a
                href="https://linkedin.com"
                target="_blank"
                rel="noopener noreferrer"
                className="text-2xl hover:opacity-80 transition"
                style={{ color: fontColor }}
              >
                <FaLinkedin />
              </a>
            </div>
          </div>
        </div>

        <div className="border-t mt-8 pt-8 text-center" style={{ borderColor: fontColor, opacity: 0.3 }}>
          <p style={{ color: fontColor, opacity: 0.85 }}>&copy; 2024 {settings?.navbar.title || 'JoVan'}. All rights reserved.</p>
        </div>
      </div>
    </footer>
  );
}
