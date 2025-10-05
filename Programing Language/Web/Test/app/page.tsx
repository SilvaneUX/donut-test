import Link from 'next/link';
import { getProducts } from '@/lib/products';
import ProductCard from '@/components/ProductCard';
import HeroSection from '@/components/HeroSection';
import HomeContent from '@/components/HomeContent';

export default function Home() {
  const products = getProducts().slice(0, 3);

  return (
    <HomeContent products={products} />
  );
}
