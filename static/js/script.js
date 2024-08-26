$(document).ready(function() {
    $('#upload-form').on('submit', function(e) {
        e.preventDefault();
        var formData = new FormData(this);

        $.ajax({
            type: 'POST',
            url: '/upload',
            data: formData,
            contentType: false,
            processData: false,
            success: function(data) {
                alert('File upload !');
            },
            error: function() {
                alert('File upload failed!');
            }
        });
    });
});
