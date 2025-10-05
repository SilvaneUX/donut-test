'use client';

import { FaWhatsapp, FaEnvelope, FaPhone, FaMapMarkerAlt } from 'react-icons/fa';
import { useSettings } from '@/contexts/SettingsContext';

export default function ContactPage() {
  const { settings } = useSettings();

  const whatsappNumber = settings?.contact.whatsappNumber || '+1234567890';
  const email = settings?.contact.email || 'info@jovan.com';
  const phone = settings?.contact.phone || '+1 (234) 567-890';
  const address = settings?.contact.address || '123 Business Street, City, Country';

  return (
    <div className="py-16 bg-gray-50 dark:bg-slate-950 min-h-screen">
      <div className="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8">
        <h1 className="text-4xl md:text-5xl font-bold text-center mb-4 text-gray-800 dark:text-gray-100">
          Contact Us
        </h1>
        <p className="text-center text-gray-600 dark:text-gray-400 mb-12 max-w-2xl mx-auto">
          Get in touch with us for any inquiries about our products or services
        </p>

        <div className="grid grid-cols-1 md:grid-cols-2 gap-8 mb-12">
          {/* Contact Information */}
          <div className="bg-white dark:bg-slate-800 rounded-lg shadow-lg p-8">
            <h2 className="text-2xl font-semibold mb-6 text-gray-800 dark:text-gray-100">Get In Touch</h2>
            
            <div className="space-y-6">
              <a
                href={`https://wa.me/${whatsappNumber.replace(/[^0-9]/g, '')}`}
                target="_blank"
                rel="noopener noreferrer"
                className="flex items-start space-x-4 p-4 rounded-lg hover:bg-gray-50 dark:hover:bg-slate-700 transition"
              >
                <FaWhatsapp className="text-3xl text-green-500 mt-1" />
                <div>
                  <h3 className="font-semibold text-gray-800 dark:text-gray-100">WhatsApp</h3>
                  <p className="text-gray-600 dark:text-gray-400">{whatsappNumber}</p>
                  <p className="text-sm text-blue-600 dark:text-blue-400">Click to chat</p>
                </div>
              </a>

              <div className="flex items-start space-x-4 p-4">
                <FaEnvelope className="text-3xl text-blue-500 mt-1" />
                <div>
                  <h3 className="font-semibold text-gray-800 dark:text-gray-100">Email</h3>
                  <a href={`mailto:${email}`} className="text-gray-600 dark:text-gray-400 hover:text-blue-600 dark:hover:text-blue-400">
                    {email}
                  </a>
                </div>
              </div>

              <div className="flex items-start space-x-4 p-4">
                <FaPhone className="text-3xl text-green-600 mt-1" />
                <div>
                  <h3 className="font-semibold text-gray-800 dark:text-gray-100">Phone</h3>
                  <a href={`tel:${phone.replace(/[^0-9+]/g, '')}`} className="text-gray-600 dark:text-gray-400 hover:text-blue-600 dark:hover:text-blue-400">
                    {phone}
                  </a>
                </div>
              </div>

              <div className="flex items-start space-x-4 p-4">
                <FaMapMarkerAlt className="text-3xl text-red-500 mt-1" />
                <div>
                  <h3 className="font-semibold text-gray-800 dark:text-gray-100">Address</h3>
                  <p className="text-gray-600 dark:text-gray-400">{address}</p>
                </div>
              </div>

              {/* Custom Contact Info */}
              {settings?.contact.customInfo && settings.contact.customInfo.map((info) => (
                <div key={info.id} className="flex items-start space-x-4 p-4">
                  {info.icon && <div className="text-3xl mt-1">{info.icon}</div>}
                  <div>
                    <h3 className="font-semibold text-gray-800 dark:text-gray-100">{info.title}</h3>
                    {info.link ? (
                      <a
                        href={info.link}
                        target="_blank"
                        rel="noopener noreferrer"
                        className="text-gray-600 dark:text-gray-400 hover:text-blue-600 dark:hover:text-blue-400"
                      >
                        {info.content}
                      </a>
                    ) : (
                      <p className="text-gray-600 dark:text-gray-400">{info.content}</p>
                    )}
                  </div>
                </div>
              ))}
            </div>
          </div>

          {/* Business Hours */}
          <div className="bg-white dark:bg-slate-800 rounded-lg shadow-lg p-8">
            <h2 className="text-2xl font-semibold mb-6 text-gray-800 dark:text-gray-100">Business Hours</h2>
            
            <div className="space-y-4">
              <div className="flex justify-between border-b border-gray-200 dark:border-slate-700 pb-3">
                <span className="font-semibold text-gray-800 dark:text-gray-100">Monday - Friday</span>
                <span className="text-gray-600 dark:text-gray-400">9:00 AM - 6:00 PM</span>
              </div>
              <div className="flex justify-between border-b border-gray-200 dark:border-slate-700 pb-3">
                <span className="font-semibold text-gray-800 dark:text-gray-100">Saturday</span>
                <span className="text-gray-600 dark:text-gray-400">9:00 AM - 2:00 PM</span>
              </div>
              <div className="flex justify-between border-b border-gray-200 dark:border-slate-700 pb-3">
                <span className="font-semibold text-gray-800 dark:text-gray-100">Sunday</span>
                <span className="text-gray-600 dark:text-gray-400">Closed</span>
              </div>
            </div>

            <div className="mt-8 p-6 bg-blue-50 dark:bg-slate-700 rounded-lg">
              <h3 className="font-semibold text-gray-800 dark:text-gray-100 mb-2">Quick Response</h3>
              <p className="text-gray-600 dark:text-gray-300 text-sm">
                For immediate assistance, reach us via WhatsApp. We typically respond within 
                a few hours during business hours.
              </p>
            </div>
          </div>
        </div>

        {/* CTA Section */}
        <div className="bg-gradient-to-r from-blue-600 to-blue-800 text-white rounded-lg shadow-lg p-8 text-center">
          <h2 className="text-3xl font-bold mb-4">Ready to Start?</h2>
          <p className="mb-6 text-lg">
            Contact us today to discuss your export and import needs
          </p>
          <a
            href={`https://wa.me/${whatsappNumber.replace(/[^0-9]/g, '')}`}
            target="_blank"
            rel="noopener noreferrer"
            className="inline-flex items-center bg-green-500 hover:bg-green-600 text-white font-semibold py-3 px-8 rounded-lg transition-colors duration-200"
          >
            <FaWhatsapp className="mr-2 text-xl" />
            Chat on WhatsApp
          </a>
        </div>
      </div>
    </div>
  );
}
