// import * as WorkboxWindow from 'workbox-window'

const swRegister = async () => {
  if (!('serviceWorker' in navigator)) {
    console.log('Service Worker not supported in the browser')
    return
  }

  const WorkboxWindow = await import('workbox-window')
  const wb = new WorkboxWindow.Workbox('./sw.bundle.js')
  // const wb = new WorkboxWindow.Workbox('./sw.bundle.js')
  // const wb = new WorkboxWindow.Workbox('./service-worker.js')
  try {
    await wb.register()
    console.log('Service worker registered')
  } catch (error) {
    console.log('Failed to register service worker', error)
  }
}

export default swRegister
