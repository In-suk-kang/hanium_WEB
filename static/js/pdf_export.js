document.getElementById('download').addEventListener('click', () => {
    const { jsPDF } = window.jspdf;
    
    html2canvas(document.body, {
        useCORS: true,  // CORS 문제를 피하기 위한 옵션
        scrollX: 0,
        scrollY: -window.scrollY  // 스크롤 위치를 고려하여 화면 캡처
    }).then(canvas => {
        const imgData = canvas.toDataURL('image/png');
        const pdf = new jsPDF('p', 'mm', 'a4');
        
        const pdfWidth = pdf.internal.pageSize.getWidth();
        const pdfHeight = pdf.internal.pageSize.getHeight();
        const imgWidth = canvas.width;
        const imgHeight = canvas.height;

        let height = imgHeight * pdfWidth / imgWidth;
        let position = 0;

        while (height > pdfHeight) {
            pdf.addImage(imgData, 'PNG', 0, position, pdfWidth, pdfHeight);
            height -= pdfHeight;
            position -= pdfHeight;
            pdf.addPage();
        }
        
        pdf.addImage(imgData, 'PNG', 0, position, pdfWidth, height);
        pdf.save('output.pdf');
    });
});