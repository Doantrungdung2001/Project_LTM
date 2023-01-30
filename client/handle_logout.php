<?php
    echo 'logout';
    $result = socket_connect($socket, $_SESSION['host_server'], $_SESSION['port']) or die("socket_connect() failed.\n");

        $msg = "02|" . $username . "|";

        $ret = socket_write($socket, $msg, strlen($msg));
        if (!$ret) die("client write fail:" . socket_strerror(socket_last_error()) . "\n");

        // receive response from server
        $response = socket_read($socket, 1024);
        if (!$response) die("client read fail:" . socket_strerror(socket_last_error()) . "\n");

        $response = explode("|", $response);
        echo $response[0];
        echo $response[1];
?>