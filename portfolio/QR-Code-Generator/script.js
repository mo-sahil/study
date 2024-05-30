function generateQRCode() {
    var text = document.getElementById('text').value;
    var qrcodeContainer = document.getElementById('qrcode');

    qrcodeContainer.innerHTML = '';

    if (text.trim() !== '') {
        new QRCode(qrcodeContainer, text);
    } else {
        alert('Please enter a valid text or URL');
    }
}

document.getElementById('text').addEventListener('keydown', function(event) {
    if (event.key === 'Enter') {
        generateQRCode();
    }
});
