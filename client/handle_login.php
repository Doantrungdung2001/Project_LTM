<?php
        session_start();
        $host = "127.0.0.1";
        $port = 8888;
        $_SESSION['host_server'] = $host;
        $_SESSION['port']= $port;

        $username = $_POST['username'];
        $password = $_POST['password'];
        
        $socket = socket_create(AF_INET, SOCK_STREAM, 0) or die("Could not create socket\n");

        // connect to server
        $result = socket_connect($socket, $_SESSION['host_server'], $_SESSION['port']) or die("socket_connect() failed.\n");

        $msg = "00|" . $username . "|". $password . "|";

        $ret = socket_write($socket, $msg, strlen($msg));
        if (!$ret) die("client write fail:" . socket_strerror(socket_last_error()) . "\n");

        // receive response from server
        $response = socket_read($socket, 1024);
        if (!$response) die("client read fail:" . socket_strerror(socket_last_error()) . "\n");

        $response = explode("|", $response);
        echo $response[1];
?>