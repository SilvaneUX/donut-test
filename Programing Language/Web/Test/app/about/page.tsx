'use client';

import { useSettings } from '@/contexts/SettingsContext';

export default function AboutPage() {
  const { settings } = useSettings();

  const description = settings?.about.description || 'JoVan is a leading export and import company specializing in local commodities.';
  const vision = settings?.about.vision || 'To become the most trusted partner in the export and import of local commodities.';
  const mission = settings?.about.mission || 'To provide exceptional service, maintain the highest quality standards, and create value for all stakeholders.';
  const customSections = settings?.about.customSections || [];

  return (
    <div className="py-16 bg-gray-50 dark:bg-slate-950 min-h-screen">
      <div className="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8">
        <h1 className="text-4xl md:text-5xl font-bold text-center mb-8 text-gray-800 dark:text-gray-100">
          About JoVan
        </h1>

        <div className="bg-white dark:bg-slate-800 rounded-lg shadow-lg p-8 mb-8">
          <h2 className="text-2xl font-semibold mb-4 text-gray-800 dark:text-gray-100">Our Story</h2>
          <p className="text-gray-700 dark:text-gray-300 mb-4 leading-relaxed">
            {description}
          </p>
          <p className="text-gray-700 dark:text-gray-300 mb-4 leading-relaxed">
            With years of experience in international trade, we have built strong relationships 
            with suppliers and customers across the globe, ensuring that high-quality products 
            reach customers worldwide while supporting local communities.
          </p>
        </div>

        <div className="grid grid-cols-1 md:grid-cols-2 gap-8 mb-8">
          <div className="bg-white dark:bg-slate-800 rounded-lg shadow-lg p-8">
            <h2 className="text-2xl font-semibold mb-4 text-gray-800 dark:text-gray-100">Our Vision</h2>
            <p className="text-gray-700 dark:text-gray-300 leading-relaxed">
              {vision}
            </p>
          </div>

          <div className="bg-white dark:bg-slate-800 rounded-lg shadow-lg p-8">
            <h2 className="text-2xl font-semibold mb-4 text-gray-800 dark:text-gray-100">Our Mission</h2>
            <p className="text-gray-700 dark:text-gray-300 leading-relaxed">
              {mission}
            </p>
          </div>
        </div>

        <div className="bg-white dark:bg-slate-800 rounded-lg shadow-lg p-8 mb-8">
          <h2 className="text-2xl font-semibold mb-6 text-gray-800 dark:text-gray-100">Why Choose Us?</h2>
          <div className="grid grid-cols-1 md:grid-cols-2 gap-6">
            <div>
              <h3 className="text-xl font-semibold mb-2 text-blue-600 dark:text-blue-400">Quality Assurance</h3>
              <p className="text-gray-700 dark:text-gray-300">
                All our products undergo rigorous quality checks to ensure they meet international standards.
              </p>
            </div>
            <div>
              <h3 className="text-xl font-semibold mb-2 text-blue-600 dark:text-blue-400">Reliable Delivery</h3>
              <p className="text-gray-700 dark:text-gray-300">
                We work with trusted logistics partners to ensure timely and safe delivery of your orders.
              </p>
            </div>
            <div>
              <h3 className="text-xl font-semibold mb-2 text-blue-600 dark:text-blue-400">Competitive Pricing</h3>
              <p className="text-gray-700 dark:text-gray-300">
                Our direct relationships with suppliers allow us to offer competitive prices without compromising quality.
              </p>
            </div>
            <div>
              <h3 className="text-xl font-semibold mb-2 text-blue-600 dark:text-blue-400">Customer Support</h3>
              <p className="text-gray-700 dark:text-gray-300">
                Our dedicated team is always ready to assist you with any queries or concerns.
              </p>
            </div>
          </div>
        </div>

        {/* Custom Sections */}
        {customSections.length > 0 && (
          <div className="space-y-8">
            {customSections.map((section) => (
              <div key={section.id} className="bg-white dark:bg-slate-800 rounded-lg shadow-lg p-8">
                <div className="flex items-start space-x-4">
                  {section.icon && (
                    <div className="text-4xl flex-shrink-0">{section.icon}</div>
                  )}
                  <div className="flex-1">
                    <h2 className="text-2xl font-semibold mb-4 text-gray-800 dark:text-gray-100">{section.title}</h2>
                    <p className="text-gray-700 dark:text-gray-300 leading-relaxed whitespace-pre-wrap">
                      {section.content}
                    </p>
                  </div>
                </div>
              </div>
            ))}
          </div>
        )}
      </div>
    </div>
  );
}
