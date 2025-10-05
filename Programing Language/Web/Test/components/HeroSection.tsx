'use client';

import Link from 'next/link';
import { useSettings } from '@/contexts/SettingsContext';

export default function HeroSection() {
  const { settings } = useSettings();

  const heroTitle = settings?.hero.title || 'Welcome to JoVan';
  const heroSubtitle = settings?.hero.subtitle || 'Your trusted partner for export and import of local commodities';
  const heroBackground = settings?.hero.useBackgroundImage && settings?.hero.backgroundImage 
    ? `url(${settings.hero.backgroundImage})` 
    : 'linear-gradient(to right, #2563eb, #1e40af)';
  const primaryColor = settings?.theme.primaryColor || '#2563eb';
  const secondaryColor = settings?.theme.secondaryColor || '#1e40af';

  // Use gradient with theme colors if no background image
  const backgroundStyle = settings?.hero.useBackgroundImage && settings?.hero.backgroundImage
    ? heroBackground
    : `linear-gradient(to right, ${primaryColor}, ${secondaryColor})`;

  return (
    <section 
      className="text-white py-20"
      style={{ 
        background: backgroundStyle,
        backgroundSize: 'cover',
        backgroundPosition: 'center'
      }}
    >
      <div className="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8 text-center">
        <h1 className="text-4xl md:text-6xl font-bold mb-6 drop-shadow-lg">
          {heroTitle}
        </h1>
        <p className="text-xl md:text-2xl mb-8 drop-shadow-lg">
          {heroSubtitle}
        </p>
        <div className="flex flex-col sm:flex-row gap-4 justify-center">
          <Link
            href="/products"
            className="bg-white font-semibold py-3 px-8 rounded-xl hover:bg-gray-100 transition"
            style={{ color: primaryColor }}
          >
            View Products
          </Link>
          <Link
            href="/contact"
            className="bg-transparent border-2 border-white text-white font-semibold py-3 px-8 rounded-xl hover:bg-white transition"
            style={{ 
              borderColor: 'white',
            }}
            onMouseEnter={(e) => {
              e.currentTarget.style.backgroundColor = 'white';
              e.currentTarget.style.color = primaryColor;
            }}
            onMouseLeave={(e) => {
              e.currentTarget.style.backgroundColor = 'transparent';
              e.currentTarget.style.color = 'white';
            }}
          >
            Contact Us
          </Link>
        </div>
      </div>
    </section>
  );
}
