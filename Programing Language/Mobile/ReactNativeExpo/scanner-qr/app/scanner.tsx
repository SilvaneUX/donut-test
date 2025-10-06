import React, { useEffect, useRef, useState } from 'react';
import { View, Text, StyleSheet, TouchableOpacity, Animated, Dimensions, Modal } from 'react-native';
import { Camera, CameraView } from 'expo-camera';
import { MaterialIcons, Ionicons } from '@expo/vector-icons';
import { useRouter } from 'expo-router';

const { width, height } = Dimensions.get('window');
const SCAN_AREA = Math.min(width * 0.78, 360);

export default function ScannerScreen({ navigation }: { navigation?: any }) {
  const [hasPermission, setHasPermission] = useState<boolean | null>(null);
  const router = useRouter();
  const [scanned, setScanned] = useState(false);
  const [data, setData] = useState<string | null>(null);
  const [torchOn, setTorchOn] = useState(false);
  const flashAnim = useRef(new Animated.Value(0)).current;

  useEffect(() => {
    (async () => {
      const { status } = await Camera.requestCameraPermissionsAsync();
      setHasPermission(status === 'granted');
    })();
  }, []);

  useEffect(() => {
    if (scanned) {
      Animated.sequence([
        Animated.timing(flashAnim, { toValue: 1, duration: 120, useNativeDriver: true }),
        Animated.timing(flashAnim, { toValue: 0, duration: 300, useNativeDriver: true }),
      ]).start();
    }
  }, [scanned]);

  const handleBarCodeScanned = ({ data }: { data: string }) => {
    if (scanned) return;
    setScanned(true);
    setData(data);

    // Jika hasil scan berupa link, buka linknya
    if (/^https?:\/\/\S+$/i.test(data)) {
      // Gunakan Linking dari react-native untuk membuka link
      import('react-native').then(({ Linking }) => {
        Linking.openURL(data).catch(() => {});
      });
    }
  };

  if (hasPermission === null) {
    return (
      <View style={styles.centered}>
        <Text style={styles.hint}>Meminta izin kamera...</Text>
      </View>
    );
  }

  if (hasPermission === false) {
    return (
      <View style={styles.centered}>
        <Text style={styles.hint}>Izin kamera ditolak. Mohon izinkan dari pengaturan.</Text>
      </View>
    );
  }

  return (
    <View style={styles.container}>
      <CameraView
        facing="back"
        style={StyleSheet.absoluteFillObject}
        enableTorch={torchOn}
        barcodeScannerSettings={{
          barcodeTypes: ['qr', 'code128', 'ean13'],
        }}
        onBarcodeScanned={handleBarCodeScanned}
      />

      {/* Top controls */}
      <View style={styles.topRow}>
        <TouchableOpacity style={styles.iconBtn} onPress={() => router.back()}>
          <Ionicons name="close" size={22} />
        </TouchableOpacity>
        <Text style={styles.title}>Scan QR / Barcode</Text>
        <TouchableOpacity style={styles.iconBtn} onPress={() => setTorchOn((s) => !s)}>
          <MaterialIcons name={torchOn ? 'flash-on' : 'flash-off'} size={22} />
        </TouchableOpacity>
      </View>

      {/* Overlay with transparent square */}
      <View style={styles.overlayContainer} pointerEvents="none">
        <View style={[styles.row, { height: (height - SCAN_AREA) / 2 }]} />

        <View style={styles.middleRow}>
          <View style={styles.side} />

          <View style={styles.scanAreaWrapper}>
            <View style={styles.scanArea} />
            {/* Animated flash when scanned */}
            {scanned && (
              <Animated.View
                style={[
                  styles.flash,
                  { opacity: flashAnim },
                ]}
              />
            )}
          </View>

          <View style={styles.side} />
        </View>

        <View style={[styles.row, { height: (height - SCAN_AREA) / 2 }]} />
      </View>

      {/* Bottom helper and actions */}
      <View style={styles.bottomRow} pointerEvents="box-none">
        <Text style={styles.hint}>Letakkan kode di dalam kotak untuk memindai secara otomatis</Text>

        <View style={styles.actionsRow}>
          <TouchableOpacity
            style={[styles.actionBtn, { opacity: scanned ? 0.6 : 1 }]}
            onPress={() => {
              setScanned(false);
              setData(null);
            }}
          >
            <Text style={styles.actionText}>Reset</Text>
          </TouchableOpacity>

          <TouchableOpacity
            style={styles.actionBtnPrimary}
            onPress={() => {
              setScanned(false);
              setData(null);
            }}
          >
            <Text style={styles.actionTextPrimary}>Scan Lagi</Text>
          </TouchableOpacity>
        </View>
      </View>

      {/* Result modal */}
      <Modal visible={!!data} animationType="slide" transparent>
        <View style={styles.modalBg}>
          <View style={styles.modalCard}>
            <Text style={styles.modalTitle}>Hasil Scan</Text>
            <Text style={styles.modalData}>{data}</Text>

            <View style={styles.modalActions}>
              <TouchableOpacity
                style={styles.secondary}
                onPress={() => {
                  setData(null);
                  setScanned(false);
                }}
              >
                <Text style={styles.secondaryText}>Tutup</Text>
              </TouchableOpacity>

              <TouchableOpacity
                style={styles.primary}
                onPress={() => {
                  navigation?.navigate?.('Home', { scanned: data });
                  setData(null);
                }}
              >
                <Text style={styles.primaryText}>Gunakan</Text>
              </TouchableOpacity>
            </View>
          </View>
        </View>
      </Modal>

    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#000',
  },
  topRow: {
    position: 'absolute',
    top: 40,
    left: 20,
    right: 20,
    flexDirection: 'row',
    alignItems: 'center',
    justifyContent: 'space-between',
    zIndex: 10,
  },
  title: {
    color: '#fff',
    fontSize: 16,
    fontWeight: '600',
  },
  iconBtn: {
    backgroundColor: 'rgba(255,255,255,0.06)',
    padding: 10,
    borderRadius: 10,
  },
  overlayContainer: {
    ...StyleSheet.absoluteFillObject,
    alignItems: 'center',
    justifyContent: 'center',
  },
  row: {
    width: '100%'
  },
  middleRow: {
    flexDirection: 'row',
    alignItems: 'center',
  },
  side: {
    flex: 1,
    backgroundColor: 'rgba(0,0,0,0.45)'
  },
  scanAreaWrapper: {
    width: SCAN_AREA,
    height: SCAN_AREA,
    alignItems: 'center',
    justifyContent: 'center',
  },
  scanArea: {
    width: '100%',
    height: '100%',
    borderRadius: 14,
    borderWidth: 2,
    borderColor: 'rgba(255,255,255,0.85)',
    backgroundColor: 'transparent',
  },
  flash: {
    ...StyleSheet.absoluteFillObject,
    backgroundColor: 'rgba(255,255,255,0.12)',
    borderRadius: 14,
  },
  bottomRow: {
    position: 'absolute',
    bottom: 36,
    left: 20,
    right: 20,
    alignItems: 'center',
    zIndex: 10,
  },
  hint: {
    color: 'rgba(255,255,255,0.9)',
    textAlign: 'center',
    marginBottom: 12,
  },
  actionsRow: {
    width: '100%',
    flexDirection: 'row',
    justifyContent: 'space-between',
  },
  actionBtn: {
    flex: 1,
    marginRight: 8,
    paddingVertical: 12,
    borderRadius: 12,
    borderWidth: 1,
    borderColor: 'rgba(255,255,255,0.08)',
    backgroundColor: 'rgba(255,255,255,0.03)',
    alignItems: 'center',
  },
  actionText: {
    color: '#fff',
    fontWeight: '600',
  },
  actionBtnPrimary: {
    flex: 1,
    marginLeft: 8,
    paddingVertical: 12,
    borderRadius: 12,
    alignItems: 'center',
    backgroundColor: '#fff',
  },
  actionTextPrimary: {
    color: '#000',
    fontWeight: '700',
  },

  modalBg: {
    flex: 1,
    backgroundColor: 'rgba(0,0,0,0.45)',
    alignItems: 'center',
    justifyContent: 'center',
  },
  modalCard: {
    width: '84%',
    backgroundColor: '#fff',
    padding: 20,
    borderRadius: 14,
    alignItems: 'center',
  },
  modalTitle: {
    fontSize: 18,
    fontWeight: '700',
    marginBottom: 8,
  },
  modalData: {
    color: '#333',
    textAlign: 'center',
    marginBottom: 18,
  },
  modalActions: {
    width: '100%',
    flexDirection: 'row',
    justifyContent: 'space-between',
  },
  primary: {
    flex: 1,
    backgroundColor: '#111827',
    paddingVertical: 10,
    borderRadius: 10,
    marginLeft: 8,
    alignItems: 'center',
  },
  primaryText: {
    color: '#fff',
    fontWeight: '700',
  },
  secondary: {
    flex: 1,
    backgroundColor: 'transparent',
    paddingVertical: 10,
    borderRadius: 10,
    marginRight: 8,
    alignItems: 'center',
    borderWidth: 1,
    borderColor: '#e5e7eb',
  },
  secondaryText: {
    color: '#111827',
    fontWeight: '600',
  },
  centered: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
  }
});
