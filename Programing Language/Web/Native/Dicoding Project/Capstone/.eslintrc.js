module.exports = {
  "env": {
    "browser": true,
    "es2021": true,
    "node": true,
  },
  "extends": [
    "airbnb-base",
    "plugin:codeceptjs/recommended"
  ],
  "overrides": [
  ],
  "parserOptions": {
    "ecmaVersion": "latest",
    "sourceType": "module"
  },
  "plugins": ["jasmine", "codeceptjs"],
  "rules": {
    "import/no-extraneous-dependencies": 0,
    "no-console": 0,
    "no-underscore-dangle": 0,
    "no-restricted-globals": 0,
    "linebreak-style": 0,
    "consistent-return": 0,
    "no-prototype-builtins": 0
  }
}
