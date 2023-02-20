<?php 
    echo "Danh sach nguoi dung";
    if(isset($_POST["search"])){
        echo "tim thay";
        echo $_POST["search"];
        echo "<script>window.location.href = 'list_user.php';</script>";
    }
?>