<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Trang chủ</title>
    <link rel="stylesheet" href="assets/css/home.css">
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.1.3/dist/css/bootstrap.min.css"
        integrity="sha384-MCw98/SFnGE8fJT3GXwEOngsV7Zt27NXFoaoApmYm81iuXoPkFOJwJ8ERdknLPMO" crossorigin="anonymous">
    <link href="https://maxcdn.bootstrapcdn.com/font-awesome/4.3.0/css/font-awesome.min.css" rel="stylesheet">
    
</head>

<body>
    <script type="text/javascript" language="JavaScript">
			function home() {
				window.location = './home.php'
			}
            function logout() {
				window.location = './logout.php'
			}
            function search() {
				window.location = './list_user.php'
			}
		</script>
    <div class="container">
        <div class="row">
            <div class="col-lg-3">
                <div class="mb-4">
                    <div class="small mb-3">Tìm kiếm</div>
                    <!-- <div class="input-group">
                        <input placeholder="Tìm kiếm hình ảnh..." type="text" class="form-control" >
                        <div class="input-group-append">
                            <button class="btn btn-secondary" type = "submit""><i class="fa fa-search" ></i></button>
                        </div>
                    </div> -->
                    <form action="handle_search.php" method="POST">
                        <input placeholder="Tìm kiếm hình ảnh..." type="text" class="form-control" name="search">
	                    <input type="submit" value="Tìm kiếm" />
                    </form>
                </div>
                <!-- <div class="mb-4">
                    <div class="small mb-3">Favorites</div>
                    <ul class="nav flex-column nav-pills">
                        <li class="nav-item"><a href="#" class="nav-link active"><i
                                    class="fa fa-fw fa-line-chart mr-2"></i>Overview</a></li>
                        <li class="nav-item"><a href="#" class="nav-link"><i
                                    class="fa fa-fw fa-calendar-o mr-2"></i>Calendar</a></li>
                    </ul>
                </div> -->
                <!-- <div class="mb-4">
                    <div class="small mb-3">Projects</div>
                    <ul class="nav flex-column nav-pills">
                        <li class="nav-item"><a href="#" class="d-flex nav-link"><i
                                    class="fa fa-fw fa-star-o align-self-center mr-2"></i>Analytics Redesign<span
                                    class="ml-auto align-self-center badge badge-secondary badge-pill">12</span></a>
                        </li>
                        <li class="nav-item"><a href="#" class="d-flex nav-link"><i
                                    class="fa fa-fw fa-star-o align-self-center mr-2"></i>New Website<span
                                    class="ml-auto align-self-center badge badge-secondary badge-pill">4</span></a></li>
                        <li class="nav-item"><a href="#" class="d-flex nav-link"><i
                                    class="fa fa-fw fa-star-o align-self-center mr-2"></i>Chart for Newsletter<span
                                    class="ml-auto align-self-center badge badge-secondary badge-pill">9</span></a></li>
                        <li class="nav-item"><a href="#" class="nav-link"><i class="fa fa-fw fa-plus mr-2"></i>Add New
                                Project</a></li>
                    </ul>
                </div> -->
                <div class="mb-4">
                    <!-- <div class="small mb-3">People</div> -->
                    <ul class="nav flex-column nav-pills">
                        <li class="nav-item">
                            <a href="profile.php" class="d-flex nav-link">
                                <div class="media">
                                    <div class="mr-3 align-self-center media-left media-middle">
                                        <div class="avatar-image avatar-image--loaded">
                                            <div class="avatar avatar--md avatar-image__image">
                                                <div class="avatar__content"><img
                                                        src="https://bootdey.com/img/Content/avatar/avatar2.png"></div>
                                            </div>
                                        </div>
                                    </div>
                                    <div class="media-body">
                                        <div class="mt-0">Đoàn Trung Dũng</div><span class="small">Lương Tài , Bắc Ninh</span>
                                    </div>
                                <!-- </div><i class="fa fa-fw fa-circle text-warning ml-auto align-self-center ml-2"></i> -->
                            </a>
                        </li>
                    </ul>
                </div>
            </div>
            <div class="col-lg-9">
                <div class="d-flex flex-column flex-md-row mb-3 mb-md-0">
                    <nav class="mr-auto d-flex align-items-center" aria-label="breadcrumb">
                        <ol class="breadcrumb">
                            <li class="active breadcrumb-item" aria-current="page" ><a href="home.php"><i
                                        class="fa fa-home"></i></a>
                            <!-- <li class="active breadcrumb-item" aria-current="page">Projects List</li> -->
                        </ol>
                        
                    </nav>
                    <div role="toolbar" class="btn-toolbar">
                        <!-- <div role="group" class="mr-auto mr-md-2 btn-group"><a
                                class="align-self-center btn btn-secondary active" aria-current="page"
                                id="tooltipShowList" href="#"><i class="fa-fw fa fa-bars"></i></a><a
                                class="align-self-center btn btn-secondary" id="tooltipShowGrid" href="#"><i
                                    class="fa-fw fa fa-th-large"></i></a></div> -->
                        <div role="group" class="btn-group">
                            <button id="tooltipAddNew" class="align-self-center btn btn-primary" onclick="logout()"><i
                                    class="fa-fw fa fa-plus" ></i> Đăng xuất</button>
                        </div>
                    </div>
                </div>
                <div class="mb-3 Card_custom-card--border_5wJKy card">
                    <div class="table-responsive-xl">
                        <table class="mb-0 table table-hover">
                            <thead>
                                <tr>
                                    <th class="align-middle bt-0">Yêu thích</th>
                                    <!-- <th class="align-middle bt-0">Hình ảnh</th> -->
                                    <th class="align-middle bt-0">Trạng thái</th>
                                    <th class="align-middle bt-0">Tên người dùng </th>
                                    <th class="align-middle bt-0">Người dùng</th>
                                    <th class="align-middle bt-0 text-right">Cài đặt</th>
                                </tr>
                            </thead>
                            <tbody>
                                <tr>
                                    <td class="align-middle">
                                        <div class="text-inverse"><a href="#"><i
                                                    class="fa fa-fw fa-lg fa-star-o"></i></a>
                                        </div>
                                    </td>
                                    <!-- <td class="align-middle">
                                        <div class="avatar-image avatar-image--loaded">
                                            <div class="avatar avatar--md avatar-image__image">
                                                <div class="avatar__content"><img
                                                        src="https://bootdey.com/img/Content/avatar/avatar1.png"></div>
                                            </div>
                                        </div>
                                    </td> -->
                                    <td class="align-middle"><span class="badge badge-success badge-pill">Active</span>
                                    </td>
                                    <td class="align-middle">
                                        <!-- <div class="mb-2 progress" style="height: 5px;">
                                            <div class="progress-bar" role="progressbar" aria-valuenow="25"
                                                aria-valuemin="0" aria-valuemax="100" style="width: 25%;"></div>
                                        </div> -->
                                        <div><span class="text-inverse">Đoàn Trung Dũng</span></div>
                                    </td>
                                    <td class="align-middle">
                                        <div class="avatar-image avatar-image--loaded">
                                            <div class="avatar avatar--md avatar-image__image">
                                                <div class="avatar__content"><img
                                                        src="https://bootdey.com/img/Content/avatar/avatar1.png"></div>
                                            </div>
                                        </div>
                                    </td>
                                    <td class="align-middle text-right">
                                        <div class="btn-group">
                                            <button type="button" aria-haspopup="true" aria-expanded="false"
                                                class="dropdown-toggle btn btn-link"><i class="fa fa-gear"></i></button>
                                            <div tabindex="-1" role="menu" aria-hidden="true"
                                                class="dropdown-menu dropdown-menu-right">
                                                <button type="button" tabindex="0" class="dropdown-item"><i
                                                        class="fa fa-fw fa-folder-open mr-2"></i>View</button>
                                                <button type="button" tabindex="0" class="dropdown-item"><i
                                                        class="fa fa-fw fa-ticket mr-2"></i>Add Task</button>
                                                <button type="button" tabindex="0" class="dropdown-item"><i
                                                        class="fa fa-fw fa-paperclip mr-2"></i>Add Files</button>
                                                <div tabindex="-1" class="dropdown-divider"></div>
                                                <button type="button" tabindex="0" class="dropdown-item"><i
                                                        class="fa fa-fw fa-trash mr-2"></i>Delete</button>
                                            </div>
                                        </div>
                                    </td>
                                </tr>
                                <tr>
                                    <td class="align-middle">
                                        <div class="text-inverse"><a href="#"><i
                                                    class="fa fa-fw fa-lg fa-star-o"></i></a>
                                        </div>
                                    </td>
                                    <!-- <td class="align-middle">
                                        <div class="avatar-image avatar-image--loaded">
                                            <div class="avatar avatar--md avatar-image__image">
                                                <div class="avatar__content"><img
                                                        src="https://bootdey.com/img/Content/avatar/avatar1.png"></div>
                                            </div>
                                        </div>
                                    </td> -->
                                    <td class="align-middle"><span
                                        <span class="badge badge-success badge-pill">Active</span>
                                    </td>
                                    <td class="align-middle">
                                        <!-- <div class="mb-2 progress" style="height: 5px;">
                                            <div class="progress-bar" role="progressbar" aria-valuenow="50"
                                                aria-valuemin="0" aria-valuemax="100" style="width: 50%;"></div>
                                        </div> -->
                                        <div><span class="text-inverse">Đoàn Trung Dũng</span></div>
                                    </td>
                                    <td class="align-middle">
                                        <div class="avatar-image avatar-image--loaded">
                                            <div class="avatar avatar--md avatar-image__image">
                                                <div class="avatar__content"><img
                                                        src="https://bootdey.com/img/Content/avatar/avatar2.png"></div>
                                            </div>
                                        </div>
                                    </td>
                                    <td class="align-middle text-right">
                                        <div class="btn-group">
                                            <button type="button" aria-haspopup="true" aria-expanded="false"
                                                class="dropdown-toggle btn btn-link"><i class="fa fa-gear"></i></button>
                                            <div tabindex="-1" role="menu" aria-hidden="true"
                                                class="dropdown-menu dropdown-menu-right">
                                                <button type="button" tabindex="0" class="dropdown-item"><i
                                                        class="fa fa-fw fa-folder-open mr-2"></i>View</button>
                                                <button type="button" tabindex="0" class="dropdown-item"><i
                                                        class="fa fa-fw fa-ticket mr-2"></i>Add Task</button>
                                                <button type="button" tabindex="0" class="dropdown-item"><i
                                                        class="fa fa-fw fa-paperclip mr-2"></i>Add Files</button>
                                                <div tabindex="-1" class="dropdown-divider"></div>
                                                <button type="button" tabindex="0" class="dropdown-item"><i
                                                        class="fa fa-fw fa-trash mr-2"></i>Delete</button>
                                            </div>
                                        </div>
                                    </td>
                                </tr>
                                <tr>
                                    <td class="align-middle">
                                        <div class="text-inverse"><a href="#"><i
                                                    class="fa fa-fw fa-lg fa-star-o"></i></a>
                                        </div>
                                    </td>
                                    <!-- <td class="align-middle">
                                        <div class="avatar-image avatar-image--loaded">
                                            <div class="avatar avatar--md avatar-image__image">
                                                <div class="avatar__content"><img
                                                        src="https://bootdey.com/img/Content/avatar/avatar1.png"></div>
                                            </div>
                                        </div>
                                    </td> -->
                                    <td class="align-middle"><span class="badge badge-success badge-pill">Active</span>
                                    </td>
                                    <td class="align-middle">
                                        <!-- <div class="mb-2 progress" style="height: 5px;">
                                            <div class="progress-bar" role="progressbar" aria-valuenow="70"
                                                aria-valuemin="0" aria-valuemax="100" style="width: 70%;"></div>
                                        </div> -->
                                        <div><span class="text-inverse">Đoàn Trung Dũng</span></div>
                                    </td>
                                    <td class="align-middle">
                                        <div class="avatar-image avatar-image--loaded">
                                            <div class="avatar avatar--md avatar-image__image">
                                                <div class="avatar__content"><img
                                                        src="https://bootdey.com/img/Content/avatar/avatar3.png"></div>
                                            </div>
                                        </div>
                                    </td>
                                    <td class="align-middle text-right">
                                        <div class="btn-group">
                                            <button type="button" aria-haspopup="true" aria-expanded="false"
                                                class="dropdown-toggle btn btn-link"><i class="fa fa-gear"></i></button>
                                            <div tabindex="-1" role="menu" aria-hidden="true"
                                                class="dropdown-menu dropdown-menu-right">
                                                <button type="button" tabindex="0" class="dropdown-item"><i
                                                        class="fa fa-fw fa-folder-open mr-2"></i>View</button>
                                                <button type="button" tabindex="0" class="dropdown-item"><i
                                                        class="fa fa-fw fa-ticket mr-2"></i>Add Task</button>
                                                <button type="button" tabindex="0" class="dropdown-item"><i
                                                        class="fa fa-fw fa-paperclip mr-2"></i>Add Files</button>
                                                <div tabindex="-1" class="dropdown-divider"></div>
                                                <button type="button" tabindex="0" class="dropdown-item"><i
                                                        class="fa fa-fw fa-trash mr-2"></i>Delete</button>
                                            </div>
                                        </div>
                                    </td>
                                </tr>
                                <tr>
                                    <td class="align-middle">
                                        <div class="text-inverse"><a href="#"><i
                                                    class="fa fa-fw fa-lg fa-star-o"></i></a>
                                        </div>
                                    </td>
                                    <!-- <td class="align-middle">
                                        <div class="avatar-image avatar-image--loaded">
                                            <div class="avatar avatar--md avatar-image__image">
                                                <div class="avatar__content"><img
                                                        src="https://bootdey.com/img/Content/avatar/avatar1.png"></div>
                                            </div>
                                        </div>
                                    </td> -->
                                    <td class="align-middle"><span class="badge badge-success badge-pill">Active</span>
                                    </td>
                                    <td class="align-middle">
                                        <!-- <div class="mb-2 progress" style="height: 5px;">
                                            <div class="progress-bar" role="progressbar" aria-valuenow="90"
                                                aria-valuemin="0" aria-valuemax="100" style="width: 90%;"></div>
                                        </div> -->
                                        <div><span class="text-inverse">Đoàn Trung Dũng</span></div>
                                    </td>
                                    <td class="align-middle">
                                        <div class="avatar-image avatar-image--loaded">
                                            <div class="avatar avatar--md avatar-image__image">
                                                <div class="avatar__content"><img
                                                        src="https://bootdey.com/img/Content/avatar/avatar4.png"></div>
                                            </div>
                                        </div>
                                    </td>
                                    <td class="align-middle text-right">
                                        <div class="btn-group">
                                            <button type="button" aria-haspopup="true" aria-expanded="false"
                                                class="dropdown-toggle btn btn-link"><i class="fa fa-gear"></i></button>
                                            <div tabindex="-1" role="menu" aria-hidden="true"
                                                class="dropdown-menu dropdown-menu-right">
                                                <button type="button" tabindex="0" class="dropdown-item"><i
                                                        class="fa fa-fw fa-folder-open mr-2"></i>View</button>
                                                <button type="button" tabindex="0" class="dropdown-item"><i
                                                        class="fa fa-fw fa-ticket mr-2"></i>Add Task</button>
                                                <button type="button" tabindex="0" class="dropdown-item"><i
                                                        class="fa fa-fw fa-paperclip mr-2"></i>Add Files</button>
                                                <div tabindex="-1" class="dropdown-divider"></div>
                                                <button type="button" tabindex="0" class="dropdown-item"><i
                                                        class="fa fa-fw fa-trash mr-2"></i>Delete</button>
                                            </div>
                                        </div>
                                    </td>
                                </tr>
                                <tr>
                                    <td class="align-middle">
                                        <div class="text-inverse"><a href="#"><i
                                                    class="fa fa-fw fa-lg fa-star-o"></i></a>
                                        </div>
                                    </td>
                                    <!-- <td class="align-middle">
                                        <div class="avatar-image avatar-image--loaded">
                                            <div class="avatar avatar--md avatar-image__image">
                                                <div class="avatar__content"><img
                                                        src="https://bootdey.com/img/Content/avatar/avatar1.png"></div>
                                            </div>
                                        </div>
                                    </td> -->
                                    <td class="align-middle"><span class="badge badge-success badge-pill">Active</span>
                                    </td>
                                    <td class="align-middle">
                                        <!-- <div class="mb-2 progress" style="height: 5px;">
                                            <div class="progress-bar" role="progressbar" aria-valuenow="25"
                                                aria-valuemin="0" aria-valuemax="100" style="width: 25%;"></div>
                                        </div> -->
                                        <div><span class="text-inverse">Đoàn Trung Dũng</span></div>
                                    </td>
                                    <td class="align-middle">
                                        <div class="avatar-image avatar-image--loaded">
                                            <div class="avatar avatar--md avatar-image__image">
                                                <div class="avatar__content"><img
                                                        src="https://bootdey.com/img/Content/avatar/avatar5.png"></div>
                                            </div>
                                        </div>
                                    </td>
                                    <td class="align-middle text-right">
                                        <div class="btn-group">
                                            <button type="button" aria-haspopup="true" aria-expanded="false"
                                                class="dropdown-toggle btn btn-link"><i class="fa fa-gear"></i></button>
                                            <div tabindex="-1" role="menu" aria-hidden="true"
                                                class="dropdown-menu dropdown-menu-right">
                                                <button type="button" tabindex="0" class="dropdown-item"><i
                                                        class="fa fa-fw fa-folder-open mr-2"></i>View</button>
                                                <button type="button" tabindex="0" class="dropdown-item"><i
                                                        class="fa fa-fw fa-ticket mr-2"></i>Add Task</button>
                                                <button type="button" tabindex="0" class="dropdown-item"><i
                                                        class="fa fa-fw fa-paperclip mr-2"></i>Add Files</button>
                                                <div tabindex="-1" class="dropdown-divider"></div>
                                                <button type="button" tabindex="0" class="dropdown-item"><i
                                                        class="fa fa-fw fa-trash mr-2"></i>Delete</button>
                                            </div>
                                        </div>
                                    </td>
                                </tr>
                                <tr>
                                    <td class="align-middle">
                                        <div class="text-inverse"><a href="#"><i
                                                    class="fa fa-fw fa-lg fa-star-o"></i></a>
                                        </div>
                                    </td>
                                    <!-- <td class="align-middle">
                                        <div class="avatar-image avatar-image--loaded">
                                            <div class="avatar avatar--md avatar-image__image">
                                                <div class="avatar__content"><img
                                                        src="https://bootdey.com/img/Content/avatar/avatar1.png"></div>
                                            </div>
                                        </div>
                                    </td> -->
                                    <td class="align-middle"><span class="badge badge-success badge-pill">Active</span>
                                    </td>
                                    <td class="align-middle">
                                        <!-- <div class="mb-2 progress" style="height: 5px;">
                                            <div class="progress-bar" role="progressbar" aria-valuenow="50"
                                                aria-valuemin="0" aria-valuemax="100" style="width: 50%;"></div>
                                        </div> -->
                                        <div><span class="text-inverse">Đoàn Trung Dũng</span></div>
                                    </td>
                                    <td class="align-middle">
                                        <div class="avatar-image avatar-image--loaded">
                                            <div class="avatar avatar--md avatar-image__image">
                                                <div class="avatar__content"><img
                                                        src="https://bootdey.com/img/Content/avatar/avatar6.png"></div>
                                            </div>
                                        </div>
                                    </td>
                                    <td class="align-middle text-right">
                                        <div class="btn-group">
                                            <button type="button" aria-haspopup="true" aria-expanded="false"
                                                class="dropdown-toggle btn btn-link"><i class="fa fa-gear"></i></button>
                                            <div tabindex="-1" role="menu" aria-hidden="true"
                                                class="dropdown-menu dropdown-menu-right">
                                                <button type="button" tabindex="0" class="dropdown-item"><i
                                                        class="fa fa-fw fa-folder-open mr-2"></i>View</button>
                                                <button type="button" tabindex="0" class="dropdown-item"><i
                                                        class="fa fa-fw fa-ticket mr-2"></i>Add Task</button>
                                                <button type="button" tabindex="0" class="dropdown-item"><i
                                                        class="fa fa-fw fa-paperclip mr-2"></i>Add Files</button>
                                                <div tabindex="-1" class="dropdown-divider"></div>
                                                <button type="button" tabindex="0" class="dropdown-item"><i
                                                        class="fa fa-fw fa-trash mr-2"></i>Delete</button>
                                            </div>
                                        </div>
                                    </td>
                                </tr>
                        
                            </tbody>
                        </table>
                    </div>
                    <div class="d-flex justify-content-center pb-0 card-footer">
                        <nav class="" aria-label="Page navigation example">
                            <ul class="pagination">
                                <li class="page-item"><a href="#" class="page-link" aria-label="Previous"><span
                                            aria-hidden="true"><i class="fa fa-fw fa-angle-left"></i></span><span
                                            class="sr-only">Previous</span></a></li>
                                <li class="page-item active"><a href="#" class="page-link">1</a></li>
                                <li class="page-item"><a href="#" class="page-link">2</a></li>
                                <li class="page-item"><a href="#" class="page-link">3</a></li>
                                <li class="page-item"><a href="#" class="page-link" aria-label="Next"><span
                                            aria-hidden="true"><i class="fa fa-fw fa-angle-right"></i></span><span
                                            class="sr-only">Next</span></a></li>
                            </ul>
                        </nav>
                    </div>
                </div>
            </div>
        </div>
    </div>
</body>
<script src="https://code.jquery.com/jquery-3.3.1.slim.min.js"
    integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo"
    crossorigin="anonymous"></script>
<script src="https://cdn.jsdelivr.net/npm/popper.js@1.14.3/dist/umd/popper.min.js"
    integrity="sha384-ZMP7rVo3mIykV+2+9J3UJ46jBk0WLaUAdn689aCwoqbBJiSnjAK/l8WvCWPIPm49"
    crossorigin="anonymous"></script>
<script src="https://cdn.jsdelivr.net/npm/bootstrap@4.1.3/dist/js/bootstrap.min.js"
    integrity="sha384-ChfqqxuZUCnJSK3+MXmPNIyE6ZbWh2IMqE241rYiqJxyMiZ6OW/JmZQ5stwEULTy"
    crossorigin="anonymous"></script>

</html>