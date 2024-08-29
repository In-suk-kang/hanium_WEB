// 파일 선택 버튼 클릭 시 숨겨진 파일 입력 요소 클릭
document.getElementById("custom-button").addEventListener("click", function() {
    document.getElementById("file-upload").click(); // 숨겨진 파일 입력 요소 클릭
});

// 파일 입력 요소에서 파일이 선택되면 파일 이름 표시
document.getElementById("file-upload").addEventListener("change", function() {
    var fileName = this.files[0] ? this.files[0].name : "선택된 파일이 없습니다.";
    document.getElementById("file-name").textContent = fileName; // 선택된 파일 이름 표시
});
