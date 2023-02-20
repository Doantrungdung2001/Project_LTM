<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Register</title>
    <link rel="stylesheet" href="assets/css/register.css">
    <link href="https://getbootstrap.com/examples/jumbotron-narrow/jumbotron-narrow.css" rel="stylesheet">
    <link rel="stylesheet" type="text/css" href="//netdna.bootstrapcdn.com/font-awesome/4.0.3/css/font-awesome.min.css">
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.1.3/dist/css/bootstrap.min.css" integrity="sha384-MCw98/SFnGE8fJT3GXwEOngsV7Zt27NXFoaoApmYm81iuXoPkFOJwJ8ERdknLPMO" crossorigin="anonymous">

    <?php
       session_start();
       $host = "127.0.0.1";
       $port = 8888;
       $_SESSION['host_server'] = $host;
       $_SESSION['port']= $port;
       $_SESSION['linkanh'] = "https://znews-photo.zingcdn.me/w1200/Uploaded/qhj_yvobvhfwbv/2018_07_18/Nguyen_Huy_Binh1.jpg";
       if(isset($_POST['register'])){
               $username = $_POST['username'];
               $password = $_POST['password'];
               
               $socket = socket_create(AF_INET, SOCK_STREAM, 0) or die("Could not create socket\n");

               // connect to server
               $result = socket_connect($socket, $_SESSION['host_server'], $_SESSION['port']) or die("socket_connect() failed.\n");

               $msg = "01|" . $username . "|". $password . "|";
               $ret = socket_write($socket, $msg, strlen($msg));
               if (!$ret) die("client write fail:" . socket_strerror(socket_last_error()) . "\n");

               // receive response from server
               $response = socket_read($socket, 1024);
               if (!$response) die("client read fail:" . socket_strerror(socket_last_error()) . "\n");
               if($response == "15\0" ){
                    $_SESSION['username'] = $username;
                    echo "<script>alert('Dang ky thanh cong');</script>";
                    echo "<script>window.location.href = 'home.php';</script>";
                }
                else{
                    echo "<script>alert('Tai khoan da ton tai');</script>";
                    echo "<script>window.location.href = 'register.php';</script>";
                }
       }                          
    ?>
</head>
<body>
<div class="container h-100">
    		<div class="row h-100">
				<div class="col-sm-10 col-md-8 col-lg-6 mx-auto d-table h-100">
					<div class="d-table-cell align-middle">

						<div class="text-center mt-4">
							<h1 class="h2">Sign Up</h1>
						</div>

						<div class="card">
							<div class="card-body">
								<div class="m-sm-4">
									<form action="register.php" method="post">
										<div class="form-group">
											<label>Name</label>
											<input class="form-control form-control-lg" type="text" name="username" placeholder="Enter your name">
										</div>
										<!-- <div class="form-group">
											<label>Company</label>
											<input class="form-control form-control-lg" type="text" name="company" placeholder="Enter your company name">
										</div> -->
										<!-- <div class="form-group">
											<label>Email</label>
											<input class="form-control form-control-lg" type="email" name="email" placeholder="Enter your email">
										</div> -->
										<div class="form-group">
											<label>Password</label>
											<input class="form-control form-control-lg" type="password" placeholder="Enter password">
										</div>
                                        <div class="form-group">
											<label>Enter Password</label>
											<input class="form-control form-control-lg" type="password" name="password" placeholder="Enter password">
										</div>
										<div class="text-center mt-3">
											<!-- <a href="" class="btn btn-lg btn-primary">Sign up</a> -->
											<button type="submit" name="register" class="btn btn-lg btn-primary">Sign up</button>
										</div>
									</form>
								</div>
							</div>
						</div>

					</div>
				</div>
			</div>
		</div>
     
</body>
        <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
        <script src="https://cdn.jsdelivr.net/npm/popper.js@1.14.3/dist/umd/popper.min.js" integrity="sha384-ZMP7rVo3mIykV+2+9J3UJ46jBk0WLaUAdn689aCwoqbBJiSnjAK/l8WvCWPIPm49" crossorigin="anonymous"></script>
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@4.1.3/dist/js/bootstrap.min.js" integrity="sha384-ChfqqxuZUCnJSK3+MXmPNIyE6ZbWh2IMqE241rYiqJxyMiZ6OW/JmZQ5stwEULTy" crossorigin="anonymous"></script>
</html>