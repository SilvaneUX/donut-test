const HtmlWebpackPlugin = require('html-webpack-plugin')
const CopyWebpackPlugin = require('copy-webpack-plugin')
// const WorkboxWebpackPlugin = require('workbox-webpack-plugin')
const ImageminWebpWebpackPlugin = require('imagemin-webp-webpack-plugin')
// const { BundleAnalyzerPlugin } = require('webpack-bundle-analyzer')
const ImageminWebpackPlugin = require('imagemin-webpack-plugin').default
const ImageminMozjpeg = require('imagemin-mozjpeg')
const BundleAnalyzerPlugin = require('webpack-bundle-analyzer').BundleAnalyzerPlugin

const path = require('path')

module.exports = {
  entry: {
    app: path.resolve(__dirname, 'src/scripts/index.js')
    // sw: path.resolve(__dirname, 'src/scripts/sw.js')
  },
  output: {
    filename: '[name].bundle.js',
    path: path.resolve(__dirname, 'dist'),
    clean: true
  },
  module: {
    rules: [
      {
        test: /\.css$/,
        use: [
          {
            loader: 'style-loader'
          },
          {
            loader: 'css-loader'
          }
        ]
      }
    ]
  },

  optimization: {
    splitChunks: {
      chunks: 'all',
      minSize: 20000,
      maxSize: 70000,
      minChunks: 1,
      maxAsyncRequests: 30,
      maxInitialRequests: 30,
      automaticNameDelimiter: '~',
      enforceSizeThreshold: 50000,
      cacheGroups: {
        defaultVendors: {
          test: /[\\/]node_modules[\\/]/,
          priority: -10
        },
        default: {
          minChunks: 2,
          priority: -20,
          reuseExistingChunk: true
        }
      }
    }
  },

  plugins: [
    new HtmlWebpackPlugin({
      filename: 'index.html',
      template: path.resolve(__dirname, 'src/templates/index.html')
    }),
    new CopyWebpackPlugin({
      patterns: [
        {
          from: path.resolve(__dirname, 'src/public'),
          to: path.resolve(__dirname, 'dist'),
          globOptions: {
            // CopyWebpackPlugin mengabaikan berkas yang berada di dalam folder images
            ignore: ['**/images/**']
          }
        }
      ]
    }),
    new ImageminWebpWebpackPlugin({
      config: [
        {
          test: /\.(jpe?g|png)/,
          options: {
            quality: 50
          }
        }
      ],
      overrideExtension: true
    }),
    new ImageminWebpackPlugin({
      plugins: [
        ImageminMozjpeg({
          quality: 50,
          progressive: true
        })
      ]
    }),
    new BundleAnalyzerPlugin({
      analyzerMode: 'static',
      openAnalyzer: false
    })
    // new WorkboxWebpackPlugin.GenerateSW({
    //   skipWaiting: true,
    //   clientsClaim: true,
    //   runtimeCaching: [
    //     {
    //       urlPattern: /^https:\/\/restaurant-api.dicoding.dev\//,
    //       handler: 'StaleWhileRevalidate',
    //       options: {
    //         cacheName: new Date().toISOString(),
    //         cacheableResponse: {
    //           statuses: [0, 200]
    //         }
    //       }
    //     }
    //   ],
    //   swDest: './sw-Workbox.bundle.js'
    // })
  ]
}
