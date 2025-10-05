'use client';

import Image from 'next/image';
import { FaWhatsapp } from 'react-icons/fa';
import { Product } from '@/types';
import { useSettings } from '@/contexts/SettingsContext';
import { useTheme } from '@/contexts/ThemeContext';
import { getFontColor } from '@/lib/colorUtils';

interface ProductCardProps {
  product: Product;
}

export default function ProductCard({ product }: ProductCardProps) {
  const { settings } = useSettings();
  const { theme } = useTheme();
  const whatsappUrl = `https://wa.me/${product.whatsappNumber.replace(/[^0-9]/g, '')}?text=Hi, I'm interested in ${encodeURIComponent(product.name)}`;

  const primaryColor = settings?.theme.primaryColor || '#2563eb';
  const fontColorMode = settings?.theme.fontColorMode || 'auto';
  const manualFontColor = settings?.theme.fontColor;
  
  // Get font color based on settings for accent elements
  const accentBgColor = theme === 'dark' ? '#1e293b' : primaryColor;
  const accentFontColor = getFontColor(accentBgColor, fontColorMode, manualFontColor);

  return (
    <div className="bg-white dark:bg-slate-800 rounded-2xl shadow-lg overflow-hidden hover:shadow-xl transition-shadow duration-300">
      <div className="relative h-48 bg-gray-200 dark:bg-slate-700">
        <Image
          src={product.image}
          alt={product.name}
          fill
          className="object-cover"
          sizes="(max-width: 768px) 100vw, (max-width: 1200px) 50vw, 33vw"
        />
      </div>
      <div className="p-6">
        <h3 className="text-xl font-semibold mb-2 text-gray-800 dark:text-gray-100">{product.name}</h3>
        <p className="text-gray-600 dark:text-gray-400 mb-2 text-sm">{product.category}</p>
        <p className="text-gray-700 dark:text-gray-300 mb-4">{product.description}</p>
        {product.price && (
          <p className="font-semibold mb-4" style={{ color: theme === 'dark' ? '#60a5fa' : primaryColor }}>
            {product.price}
          </p>
        )}
        <a
          href={whatsappUrl}
          target="_blank"
          rel="noopener noreferrer"
          className="flex items-center justify-center bg-green-500 hover:bg-green-600 text-white font-semibold py-2 px-4 rounded-xl transition-colors duration-200"
        >
          <FaWhatsapp className="mr-2 text-xl" />
          Contact via WhatsApp
        </a>
      </div>
    </div>
  );
}
