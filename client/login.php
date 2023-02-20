<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Logn In</title>
    <link rel="stylesheet" href="assets/css/style.css">
    <link href="//maxcdn.bootstrapcdn.com/bootstrap/4.1.1/css/bootstrap.min.css" rel="stylesheet" id="bootstrap-css">
    <?php
                session_start();
                $host = "127.0.0.1";
                $port = 8888;
                $_SESSION['host_server'] = $host;
                $_SESSION['port']= $port;
                $_SESSION['linkanh'] = "https://znews-photo.zingcdn.me/w1200/Uploaded/qhj_yvobvhfwbv/2018_07_18/Nguyen_Huy_Binh1.jpg";
                if(isset($_POST['login'])){
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
                        if($response == "16\0" ){
                            echo "<script>window.location.href = 'home.php';</script>";
                        }
                        else{
                            echo "<script>window.location.href = 'login.php';</script>";
                        }
                }                 
        ?>
</head>

<body>

    <div id="login">
        <h3 class="text-center text-white pt-5">Login form</h3>
        <div class="container">
            <div id="login-row" class="row justify-content-center align-items-center">
                <div id="login-column" class="col-md-6">
                    <div id="login-box" class="col-md-12">
                        <form id="login-form" class="form" action="login.php" method="post">
                            <h3 class="text-center text-info">Login</h3>
                            <div class="form-group">
                                <label for="username" class="text-info">Username:</label><br>
                                <input type="text" name="username" id="username" class="form-control">
                            </div>
                            <div class="form-group">
                                <label for="password" class="text-info">Password:</label><br>
                                <input type="text" name="password" id="password" class="form-control">
                            </div>
                            <div class="form-group">
                                <label for="remember-me" class="text-info"><span>Remember me</span> <span><input
                                            id="remember-me" name="remember-me" type="checkbox"></span></label><br>
                                <input type="submit" name="login" class="btn btn-info btn-md" value="submit">
                            </div>
                            <div id="register-link" class="text-right">
                                <a href="#" class="text-info">Register here</a>
                            </div>
                        </form>
                    </div>
                </div>
            </div>
        </div>
    </div>
</body>
<script src="//maxcdn.bootstrapcdn.com/bootstrap/4.1.1/js/bootstrap.min.js"></script>
<script src="//cdnjs.cloudflare.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>

</html>
