<?php
    session_start();
    if (isset($_SESSION['username'])) {
            // create socket
            $socket = socket_create(AF_INET, SOCK_STREAM, 0) or die("Could not create socket\n");

            // connect to server
            $result = socket_connect($socket, $_SESSION['host_server'], $_SESSION['port']) or die("socket_connect() failed.\n");
            // 
            $msg = "02|" . $_SESSION['username'] . "|";

            $ret = socket_write($socket, $msg, strlen($msg));
            if (!$ret) die("client write fail:" . socket_strerror(socket_last_error()) . "\n");

            // receive response from server
            $response = socket_read($socket, 1024);
            if (!$response) die("client read fail:" . socket_strerror(socket_last_error()) . "\n");
            echo $response;

            // split response from server
            if ($response == "17\0") {
                echo "<script>alert('Are you sure logout ?');</script>";
                echo "<script>window.location.href = 'login.php';</script>";
                
            } else {
                echo "<script>alert('fail!');</script>";
                echo "<script>window.location.href = 'home.php';</script>";
            }

            // close socket
            socket_close($socket);
        }
    
?>