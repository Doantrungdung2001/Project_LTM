<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Danh sách người dùng</title>
  <link rel="stylesheet" href="assets/css/list_user.css">
  <link rel="stylesheet" href="assets/css/home.css">
  <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/5.13.1/css/all.min.css"
    integrity="sha256-2XFplPlrFClt0bIdPgpz8H7ojnk10H69xRqd9+uTShA=" crossorigin="anonymous" />
  <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.5.3/dist/css/bootstrap.min.css" 
    integrity="sha384-TX8t27EcRE3e/ihU7zmQxVncDAy5uIKz4rEkgIXeMed4M0jlfIDPvg6uqKI2xXr2" crossorigin="anonymous">
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/5.15.4/css/all.min.css" />

</head>

<body>
<div class="container">
        <div class="row">
            <div class="col-lg-9">
                <div class="mb-4">
                    <div class="small mb-3">Tìm kiếm</div>
                    <div class="input-group">
                        <input placeholder="Tìm kiếm hình ảnh..." type="text" class="form-control">
                        <div class="input-group-append">
                            <button class="btn btn-secondary"><i class="fa fa-search"></i></button>
                        </div>
                    </div>
                </div>
        </div>
        <div class="col-lg-9">
                <div class="d-flex flex-column flex-md-row mb-3 mb-md-0">
                    <nav class="mr-auto d-flex align-items-center" aria-label="breadcrumb">
                        <ol class="breadcrumb">
                            <li class="active breadcrumb-item" aria-current="page"><a href="home.php"><i
                                        class="fa fa-home"></i></a></li>
                            <!-- <li class="active breadcrumb-item" aria-current="page">Projects List</li> -->
                        </ol>
                    </nav>
                </div>  
  </div>       
  <div class="container mt-3 mb-4">
    <div class="col-lg-9 mt-4 mt-lg-0">
      <div class="row">
        <div class="col-md-12">
          <div class="user-dashboard-info-box table-responsive mb-0 bg-white p-4 shadow-sm">
            <table class="table manage-candidates-top mb-0">
              <thead>
                <tr>
                  <th>Người dùng</th>
                  <th class="text-center">Hình ảnh</th>
                  <th class="action text-right"></th>
                </tr>
              </thead>
              <tbody>
              <tr class="candidates-list">
                  <td class="title">
                    <div class="thumb">
                      <img class="img-fluid" src="https://bootdey.com/img/Content/avatar/avatar3.png" alt="">
                    </div>
                    <div class="candidate-list-details">
                      <div class="candidate-list-info">
                        <div class="candidate-list-title">
                          <h5 class="mb-0"><a href="#">Vickie Meyer</a></h5>
                        </div>
                        <div class="candidate-list-option">
                          <ul class="list-unstyled">
                            <li><i class="fas fa-filter pr-1"></i>HUST</li>
                            <li><i class="fas fa-map-marker-alt pr-1"></i>Lương Tài , Bắc Ninh</li>
                          </ul>
                        </div>
                      </div>
                    </div>
                  </td>
                  <td class="align-middle">
                                        <div class="avatar-image avatar-image--loaded">
                                            <div class="avatar avatar--md avatar-image__image">
                                                <div class="avatar__content"><img
                                                        src="https://bootdey.com/img/Content/avatar/avatar6.png"></div>
                                          </div>
                              </div>
                    </td>
                  <td>
                  <td>
                    <ul class="list-unstyled mb-0 d-flex justify-content-end">
                        <!-- <li><a href="#" class="text-primary" data-toggle="tooltip" title="" data-original-title="view"><i
                              class="far fa-eye"></i></a></li>
                        <li><a href="#" class="text-info" data-toggle="tooltip" title="" data-original-title="Edit"><i
                              class="fas fa-pencil-alt"></i></a></li>
                        <li><a href="#" class="text-danger" data-toggle="tooltip" title="" data-original-title="Delete"><i
                              class="far fa-trash-alt"></i></a></li> -->
                        <i class="fas fa-download"></i>
                      </ul>
                  </td>
                </tr>
                <tr class="candidates-list">
                  <td class="title">
                    <div class="thumb">
                      <img class="img-fluid" src="https://bootdey.com/img/Content/avatar/avatar1.png" alt="">
                    </div>
                    <div class="candidate-list-details">
                      <div class="candidate-list-info">
                        <div class="candidate-list-title">
                          <h5 class="mb-0"><a href="#">Ronald Bradley</a></h5>
                        </div>
                        <div class="candidate-list-option">
                          <ul class="list-unstyled">
                            <li><i class="fas fa-filter pr-1"></i>HUST</li>
                            <li><i class="fas fa-map-marker-alt pr-1"></i>Lương Tài , Bắc Ninh</li>
                          </ul>
                        </div>
                      </div>
                    </div>
                  </td>
                  <td class="align-middle">
                                        <div class="avatar-image avatar-image--loaded">
                                            <div class="avatar avatar--md avatar-image__image">
                                                <div class="avatar__content"><img
                                                        src="https://bootdey.com/img/Content/avatar/avatar6.png"></div>
                                          </div>
                              </div>
                    </td>
                  <td>
                  <td>
                    <ul class="list-unstyled mb-0 d-flex justify-content-end">
                        <!-- <li><a href="#" class="text-primary" data-toggle="tooltip" title="" data-original-title="view"><i
                              class="far fa-eye"></i></a></li>
                        <li><a href="#" class="text-info" data-toggle="tooltip" title="" data-original-title="Edit"><i
                              class="fas fa-pencil-alt"></i></a></li>
                        <li><a href="#" class="text-danger" data-toggle="tooltip" title="" data-original-title="Delete"><i
                              class="far fa-trash-alt"></i></a></li> -->
                        <i class="fas fa-download"></i>
                      </ul>
                  </td>
                </tr>
                <tr class="candidates-list">
                  <td class="title">
                    <div class="thumb">
                      <img class="img-fluid" src="https://bootdey.com/img/Content/avatar/avatar2.png" alt="">
                    </div>
                    <div class="candidate-list-details">
                      <div class="candidate-list-info">
                        <div class="candidate-list-title">
                          <h5 class="mb-0"><a href="#">Rafael Briggs</a></h5>
                        </div>
                        <div class="candidate-list-option">
                          <ul class="list-unstyled">
                            <li><i class="fas fa-filter pr-1"></i>HUST</li>
                            <li><i class="fas fa-map-marker-alt pr-1"></i>Lương Tài , Bắc Ninh</li>
                          </ul>
                        </div>
                      </div>
                    </div>
                  </td>
                  <td class="align-middle">
                                        <div class="avatar-image avatar-image--loaded">
                                            <div class="avatar avatar--md avatar-image__image">
                                                <div class="avatar__content"><img
                                                        src="https://bootdey.com/img/Content/avatar/avatar6.png"></div>
                                          </div>
                              </div>
                    </td>
                  <td>
                  <td>
                    <ul class="list-unstyled mb-0 d-flex justify-content-end">
                        <!-- <li><a href="#" class="text-primary" data-toggle="tooltip" title="" data-original-title="view"><i
                              class="far fa-eye"></i></a></li>
                        <li><a href="#" class="text-info" data-toggle="tooltip" title="" data-original-title="Edit"><i
                              class="fas fa-pencil-alt"></i></a></li>
                        <li><a href="#" class="text-danger" data-toggle="tooltip" title="" data-original-title="Delete"><i
                              class="far fa-trash-alt"></i></a></li> -->
                        <i class="fas fa-download"></i>
                      </ul>
                  </td>
                </tr>
                <tr class="candidates-list">
                  <td class="title">
                    <div class="thumb">
                      <img class="img-fluid" src="https://bootdey.com/img/Content/avatar/avatar3.png" alt="">
                    </div>
                    <div class="candidate-list-details">
                      <div class="candidate-list-info">
                        <div class="candidate-list-title">
                          <h5 class="mb-0"><a href="#">Vickie Meyer</a></h5>
                        </div>
                        <div class="candidate-list-option">
                          <ul class="list-unstyled">
                            <li><i class="fas fa-filter pr-1"></i>HUST</li>
                            <li><i class="fas fa-map-marker-alt pr-1"></i>Lương Tài , Bắc Ninh</li>
                          </ul>
                        </div>
                      </div>
                    </div>
                  </td>
                  <td class="align-middle">
                                        <div class="avatar-image avatar-image--loaded">
                                            <div class="avatar avatar--md avatar-image__image">
                                                <div class="avatar__content"><img
                                                        src="https://bootdey.com/img/Content/avatar/avatar6.png"></div>
                                          </div>
                              </div>
                    </td>
                  <td>
                  <td>
                    <ul class="list-unstyled mb-0 d-flex justify-content-end">
                        <!-- <li><a href="#" class="text-primary" data-toggle="tooltip" title="" data-original-title="view"><i
                              class="far fa-eye"></i></a></li>
                        <li><a href="#" class="text-info" data-toggle="tooltip" title="" data-original-title="Edit"><i
                              class="fas fa-pencil-alt"></i></a></li>
                        <li><a href="#" class="text-danger" data-toggle="tooltip" title="" data-original-title="Delete"><i
                              class="far fa-trash-alt"></i></a></li> -->
                        <i class="fas fa-download"></i>
                      </ul>
                  </td>
                </tr>
               
              </tbody>
            </table>
            <div class="text-center mt-3 mt-sm-3">
              <ul class="pagination justify-content-center mb-0">
                <li class="page-item disabled"> <span class="page-link">Prev</span> </li>
                <li class="page-item active" aria-current="page"><span class="page-link">1 </span> <span
                    class="sr-only">(current)</span></li>
                <li class="page-item"><a class="page-link" href="#">2</a></li>
                <li class="page-item"><a class="page-link" href="#">3</a></li>
                <li class="page-item"><a class="page-link" href="#">...</a></li>
                <li class="page-item"> <a class="page-link" href="#">Next</a> </li>
              </ul>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>
</body>
<script src="https://code.jquery.com/jquery-3.5.1.slim.min.js" integrity="sha384-DfXdz2htPH0lsSSs5nCTpuj/zy4C+OGpamoFVy38MVBnE+IbbVYUew+OrCXaRkfj" crossorigin="anonymous"></script>
<script src="https://cdn.jsdelivr.net/npm/bootstrap@4.5.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-ho+j7jyWK8fNQe+A12Hb8AhRq26LrZ/JpcUGGOn+Y7RsweNrtN/tE3MoK7ZeZDyx" crossorigin="anonymous"></script>
<script src="https://code.jquery.com/jquery-3.5.1.slim.min.js" integrity="sha384-DfXdz2htPH0lsSSs5nCTpuj/zy4C+OGpamoFVy38MVBnE+IbbVYUew+OrCXaRkfj" crossorigin="anonymous"></script>
<script src="https://cdn.jsdelivr.net/npm/popper.js@1.16.1/dist/umd/popper.min.js" integrity="sha384-9/reFTGAW83EW2RDu2S0VKaIzap3H66lZH81PoYlFhbGU+6BZp6G7niu735Sk7lN" crossorigin="anonymous"></script>
<script src="https://cdn.jsdelivr.net/npm/bootstrap@4.5.3/dist/js/bootstrap.min.js" integrity="sha384-w1Q4orYjBQndcko6MimVbzY0tgp4pWB4lZ7lr30WKz0vr/aWKhXdBNmNb5D92v7s" crossorigin="anonymous"></script>
</html>