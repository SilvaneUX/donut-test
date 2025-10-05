'use client';

import Link from 'next/link';
import ProductCard from '@/components/ProductCard';
import HeroSection from '@/components/HeroSection';
import { useSettings } from '@/contexts/SettingsContext';
import { Product } from '@/types';

interface HomeContentProps {
  products: Product[];
}

export default function HomeContent({ products }: HomeContentProps) {
  const { settings } = useSettings();
  const primaryColor = settings?.theme.primaryColor || '#2563eb';

  return (
    <div>
      {/* Hero Section */}
      <HeroSection />

      {/* Features Section */}
      <section className="py-16 bg-gray-50 dark:bg-slate-900">
        <div className="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8">
          <h2 className="text-3xl md:text-4xl font-bold text-center mb-12 text-gray-800 dark:text-gray-100">
            Why Choose JoVan?
          </h2>
          <div className="grid grid-cols-1 md:grid-cols-3 gap-8">
            <div className="bg-white dark:bg-slate-800 p-6 rounded-2xl shadow-md text-center">
              <div className="text-4xl mb-4 text-blue-600 dark:text-blue-400">🌍</div>
              <h3 className="text-xl font-semibold text-black dark:text-gray-100 mb-2">Global Reach</h3>
              <p className="text-gray-600 dark:text-gray-400">
                We connect local commodities to international markets
              </p>
            </div>
            <div className="bg-white dark:bg-slate-800 p-6 rounded-2xl shadow-md text-center">
              <div className="text-4xl mb-4 text-blue-600 dark:text-blue-400">✓</div>
              <h3 className="text-xl font-semibold text-black dark:text-gray-100 mb-2">Quality Assured</h3>
              <p className="text-gray-600 dark:text-gray-400">
                All products meet international quality standards
              </p>
            </div>
            <div className="bg-white dark:bg-slate-800 p-6 rounded-2xl shadow-md text-center">
              <div className="text-4xl mb-4 text-blue-600 dark:text-blue-400">🤝</div>
              <h3 className="text-xl font-semibold text-black dark:text-gray-100 mb-2">Trusted Partner</h3>
              <p className="text-gray-600 dark:text-gray-400">
                Years of experience in import and export business
              </p>
            </div>
          </div>
        </div>
      </section>

      {/* Featured Products */}
      <section className="py-16 dark:bg-slate-950">
        <div className="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8">
          <h2 className="text-3xl md:text-4xl font-bold text-center mb-12 text-gray-800 dark:text-gray-100">
            Featured Products
          </h2>
          <div className="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-3 gap-8">
            {products.map((product) => (
              <ProductCard key={product.id} product={product} />
            ))}
          </div>
          <div className="text-center mt-12">
            <Link
              href="/products"
              className="inline-block text-white font-semibold py-3 px-8 rounded-xl transition hover:opacity-90"
              style={{ backgroundColor: primaryColor }}
            >
              View All Products
            </Link>
          </div>
        </div>
      </section>
    </div>
  );
}
