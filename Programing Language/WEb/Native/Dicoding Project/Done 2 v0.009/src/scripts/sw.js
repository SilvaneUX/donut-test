import 'regenerator-runtime'
import CacheHelper from './utils/cache-helper'

// Daftar asset yang akan dicaching
const assetsToCache = [
  './',
  './icons/icon-192x192.png',
  './icons/icon-256x256.png',
  './icons/icon-384x384.png',
  './icons/icon-512x512.png',
  './index.html',
  './app.bundle.js',
  './app.webmanifest',
  './sw.bundle.js'
]

self.addEventListener('install', (event) => {
  event.waitUntil(CacheHelper.cachingAppShell([...assetsToCache]))
})

self.addEventListener('activate', (event) => {
  event.waitUntil(CacheHelper.deleteOldCache())
})

self.addEventListener('fetch', (event) => {
  event.respondWith(CacheHelper.revalidateCache(event.request))
})
