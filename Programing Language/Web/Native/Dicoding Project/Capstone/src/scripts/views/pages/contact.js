import '../../component/contact-us';
import emailjs from '@emailjs/browser';
import swal from 'sweetalert';

const Contact = {
    async render() {
      return `
      <contact-us></contact-us>
      `;
    },
  
    async afterRender() {
    document.title = 'Contact Us - Young Health';

    const submitButton = document.querySelector('input[name="submit"]');
    submitButton.addEventListener('click', async () => {
      const name = document.querySelector('input[name="nama"]').value;
      const phoneNumber = document.querySelector('input[name="telp"]').value;
      const email = document.querySelector('input[name="email"]').value;
      const message = document.querySelector('textarea[name="pesan"]').value;
      if (!name || !phoneNumber || !email || !message) {
        swal('Error', 'Harap Isi Data Dengan Lengkap!.', 'error');
        return;
      }
      const templateParams = {
        from_name: name,
        phone_number: phoneNumber,
        from_email: email,
        message: message,
      };

    emailjs.send('service_sgdd6st','template_9k7q4t2', templateParams, 'kcEzo1Ssq7TCoqEmx')
        .then((response) => {
          console.log('SUCCESS!', response.status, response.text);
          swal('Success', 'Pesan berhasil dikirim! Kami akan segera menghubungi Anda.', 'success');
        }, (err) => {
          console.log('FAILED...', err);
          swal('Error', 'An error occurred while sending the message. Please try again later.', 'error');
        });

    });
    },
  };
  
  export default Contact;
  