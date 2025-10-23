module.exports = {
  devServer: {
    proxy: {
      '/api': {
        target: 'http://localhost:18080',
        changeOrigin: true
      }
    }
  }
}