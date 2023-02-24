<?php 
    session_start();
    if(isset($_POST["search"])){
        $namefile = $_POST["search"];
        $username = $_SESSION['username'];
        $socket = socket_create(AF_INET, SOCK_STREAM, 0) or die("Could not create socket\n");

        // connect to server
        $result = socket_connect($socket, $_SESSION['host_server'], $_SESSION['port']) or die("socket_connect() failed.\n");

        $msg = "03|" . $username . "|". $namefile . "|";
        // echo $msg;
        $ret = socket_write($socket, $msg, strlen($msg));
        if (!$ret) die("client write fail:" . socket_strerror(socket_last_error()) . "\n");

        // receive response from server
        $response = socket_read($socket, 1024);
        if (!$response) die("client read fail:" . socket_strerror(socket_last_error()) . "\n");
        echo "<script>window.location.href = 'login.php';</script>";
        echo $response;
        // if($response == "16\0" ){
        //     $_SESSION['username'] = $username;
        //     echo "<script>window.location.href = 'home.php';</script>";
        // }
        // else{
            
        // }
}   
?>