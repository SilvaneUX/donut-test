const passwordEl = document.getElementById('password');
const copyBtn = document.getElementById('copyBtn');
const generateBtn = document.getElementById('generate');
const lengthEl = document.getElementById('length');
const lengthValue = document.getElementById('lengthValue');
const meterFill = document.getElementById('meterFill');
const strengthText = document.getElementById('strengthText');

const uppercaseEl = document.getElementById('uppercase');
const lowercaseEl = document.getElementById('lowercase');
const numbersEl = document.getElementById('numbers');
const symbolsEl = document.getElementById('symbols');

const userPasswordEl = document.getElementById('userPassword');
const checkBtn = document.getElementById('checkBtn');
const userMeter = document.getElementById('userMeter');
const userStrength = document.getElementById('userStrength');


const upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const lower = "abcdefghijklmnopqrstuvwxyz";
const number = "0123456789";
const symbol = "!@#$%^&*()_+~`|}{[]:;?><,./-=";

lengthEl.addEventListener('input', () => {
  lengthValue.textContent = lengthEl.value;
});

generateBtn.addEventListener('click', () => {
  const length = +lengthEl.value;
  let chars = '';
  if (uppercaseEl.checked) chars += upper;
  if (lowercaseEl.checked) chars += lower;
  if (numbersEl.checked) chars += number;
  if (symbolsEl.checked) chars += symbol;

  if (!chars) {
    passwordEl.value = '⚠️ Select at least one option!';
    return;
  }

  let password = '';
  for (let i = 0; i < length; i++) {
    password += chars.charAt(Math.floor(Math.random() * chars.length));
  }

  passwordEl.value = password;
  checkStrength(password, meterFill, strengthText);
});

copyBtn.addEventListener('click', () => {
  if (!passwordEl.value) return;
  navigator.clipboard.writeText(passwordEl.value);
  copyBtn.textContent = 'Copied!';
  setTimeout(() => (copyBtn.textContent = 'Copy'), 1200);
});

checkBtn.addEventListener('click', () => {
  const pwd = userPasswordEl.value.trim();
  if (!pwd) return;
  checkStrength(pwd, userMeter, userStrength);
});

function checkStrength(password, meter, text) {
  let strength = 0;
  if (password.length >= 8) strength++;
  if (/[A-Z]/.test(password)) strength++;
  if (/[a-z]/.test(password)) strength++;
  if (/[0-9]/.test(password)) strength++;
  if (/[^A-Za-z0-9]/.test(password)) strength++;

  const percent = (strength / 5) * 100;
  meter.style.width = `${percent}%`;

  if (strength <= 2) {
    meter.style.background = '#ef4444';
    text.textContent = 'Weak';
  } else if (strength === 3 || strength === 4) {
    meter.style.background = '#f59e0b';
    text.textContent = 'Medium';
  } else {
    meter.style.background = '#10b981';
    text.textContent = 'Strong';
  }
}

