'use client';

import { createContext, useContext, useEffect, useState, ReactNode } from 'react';

export interface SiteSettings {
  theme: {
    primaryColor: string;
    secondaryColor: string;
    fontColorMode: 'auto' | 'manual';
    fontColor?: string;
  };
  navbar: {
    logo: string;
    title: string;
    showLogo: boolean;
  };
  hero: {
    title: string;
    subtitle: string;
    backgroundImage: string;
    useBackgroundImage: boolean;
  };
  about: {
    description: string;
    vision: string;
    mission: string;
    customSections?: Array<{
      id: string;
      title: string;
      content: string;
      icon?: string;
    }>;
  };
  contact: {
    whatsappNumber: string;
    email: string;
    phone: string;
    address: string;
    customInfo?: Array<{
      id: string;
      title: string;
      content: string;
      icon?: string;
      link?: string;
    }>;
  };
}

interface SettingsContextType {
  settings: SiteSettings | null;
  updateSettings: (settings: SiteSettings) => Promise<void>;
  loading: boolean;
}

const SettingsContext = createContext<SettingsContextType | undefined>(undefined);

const defaultSettings: SiteSettings = {
  theme: {
    primaryColor: '#2563eb',
    secondaryColor: '#1e40af',
    fontColorMode: 'auto',
    fontColor: '#ffffff',
  },
  navbar: {
    logo: '',
    title: 'JoVan',
    showLogo: false,
  },
  hero: {
    title: 'Welcome to JoVan',
    subtitle: 'Your trusted partner for export and import of local commodities',
    backgroundImage: '',
    useBackgroundImage: false,
  },
  about: {
    description: 'JoVan is a leading import and export company specializing in local commodities.',
    vision: 'To be the premier bridge connecting local commodities to global markets.',
    mission: 'To facilitate international trade while supporting local producers and maintaining the highest quality standards.',
    customSections: [],
  },
  contact: {
    whatsappNumber: '+1234567890',
    email: 'info@jovan.com',
    phone: '+1 (234) 567-890',
    address: '123 Business Street, City, Country',
    customInfo: [],
  },
};

export function SettingsProvider({ children }: { children: ReactNode }) {
  const [settings, setSettings] = useState<SiteSettings | null>(null);
  const [loading, setLoading] = useState(true);

  useEffect(() => {
    fetchSettings();
  }, []);

  const fetchSettings = async () => {
    try {
      const response = await fetch('/api/settings');
      if (response.ok) {
        const data = await response.json();
        setSettings(data);
      } else {
        setSettings(defaultSettings);
      }
    } catch (error) {
      console.error('Error fetching settings:', error);
      setSettings(defaultSettings);
    } finally {
      setLoading(false);
    }
  };

  const updateSettings = async (newSettings: SiteSettings) => {
    try {
      const response = await fetch('/api/settings', {
        method: 'PUT',
        headers: {
          'Content-Type': 'application/json',
        },
        body: JSON.stringify(newSettings),
      });

      if (response.ok) {
        const data = await response.json();
        setSettings(data);
      }
    } catch (error) {
      console.error('Error updating settings:', error);
      throw error;
    }
  };

  return (
    <SettingsContext.Provider value={{ settings, updateSettings, loading }}>
      {children}
    </SettingsContext.Provider>
  );
}

export function useSettings() {
  const context = useContext(SettingsContext);
  if (context === undefined) {
    throw new Error('useSettings must be used within a SettingsProvider');
  }
  return context;
}
