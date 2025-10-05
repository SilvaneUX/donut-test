import fs from 'fs';
import path from 'path';
import { Product } from '@/types';

const productsFilePath = path.join(process.cwd(), 'data', 'products.json');

export function getProducts(): Product[] {
  try {
    const fileContents = fs.readFileSync(productsFilePath, 'utf8');
    return JSON.parse(fileContents);
  } catch (error) {
    console.error('Error reading products:', error);
    return [];
  }
}

export function getProductById(id: string): Product | undefined {
  const products = getProducts();
  return products.find(product => product.id === id);
}

export function addProduct(product: Omit<Product, 'id' | 'createdAt'>): Product {
  const products = getProducts();
  const newProduct: Product = {
    ...product,
    id: Date.now().toString(),
    createdAt: new Date().toISOString(),
  };
  products.push(newProduct);
  fs.writeFileSync(productsFilePath, JSON.stringify(products, null, 2));
  return newProduct;
}

export function updateProduct(id: string, updates: Partial<Product>): Product | null {
  const products = getProducts();
  const index = products.findIndex(p => p.id === id);
  
  if (index === -1) return null;
  
  products[index] = { ...products[index], ...updates };
  fs.writeFileSync(productsFilePath, JSON.stringify(products, null, 2));
  return products[index];
}

export function deleteProduct(id: string): boolean {
  const products = getProducts();
  const filteredProducts = products.filter(p => p.id !== id);
  
  if (products.length === filteredProducts.length) return false;
  
  fs.writeFileSync(productsFilePath, JSON.stringify(filteredProducts, null, 2));
  return true;
}
