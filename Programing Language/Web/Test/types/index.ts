export interface Product {
  id: string;
  name: string;
  description: string;
  category: string;
  image: string;
  whatsappNumber: string;
  price?: string;
  createdAt: string;
}

export interface User {
  id: string;
  email: string;
  password: string;
  role: 'admin';
}
