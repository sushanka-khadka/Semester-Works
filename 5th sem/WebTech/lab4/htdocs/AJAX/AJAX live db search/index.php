<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Live Search using AJAX</title>
    <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
    <link rel="stylesheet" href="style.css">
</head>
<body>
    <div class ='search-box'>
        <h3>Live Search using AJAX</h3>
        <input type='text' id='search' placeholder='Search by name...'>
        <div id='result'></div>
    </div>
    <script>
        $(document).ready(function (){
            $('#search').on('keyup', function () {
                let query = $(this).val();
                if ( query.length > 0) {
                    $.ajax({
                        url: 'search.php', 
                        type: 'POST',
                        data: {query: query},
                        success: function (data) {
                            $("#result").html(data);
                        }
                    });
                }else
                    $('#result').html('');
            });
        });
    </script>
</body>
</html>