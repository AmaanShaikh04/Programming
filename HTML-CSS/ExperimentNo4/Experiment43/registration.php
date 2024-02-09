<?php
require_once('connection.php');
?>
<html>
<head>
<title>
    User Registration
</title>
<link rel = "stylesheet" href = "first.css">
</head>
<body>
    <div>
        <?php
            if(isset($_POST['create']))
            {
                $passenger =$_POST['passenger'];
                $afrom =$_POST['afrom'];
                $tob = $_POST['tob'];
                $departure =$_POST['departure'];
                $joindate= $_POST['arrival'];
                $phonenumber= $_POST['phonenumber'];
                $email= $_POST['email'];

                $sql = "INSERT INTO flight (passenger, afrom, tob, departure, arrival,phonenumber,email) VALUES(?,?,?,?,?,?,?)";
                $stmtinsert = $db->prepare($sql);
                $result = $stmtinsert->execute([$passenger, $afrom, $tob, $departure, $joindate, $phonenumber,$email]);

                if($result)
                {
                    echo 'successfully saved';
                }
                else{
                    echo 'There is an error';
                }
            }
        ?>
    </div>
    <div>
        <form action="registration.php" method="post">
        <div class="navbar">
            <a  href="registration.php">Insert</a> 
            <a href="display.php">Display</a> 
            <a href="update.php">Update</a> 
            <a href="delete.php">Delete</a>
    </div>
            <div class = "container">
                <h1>Flight Passenger Booking</h1>
                <p>Fill up the form with correct values</p>
                <lable for = "passenger"><b>Passenger Name</b></lable>
                <input type ="text" name="passenger" required>

                <lable for = "afrom"><b>From </b></lable>
                <input type ="text" name="afrom" required>

                <lable for = "tob"><b>To </b></lable>
                <input type ="text" name="tob" required>

                <lable for = "departure"><b>Departure</b></lable>
                <input type ="text" name="departure" required>

                <lable for = "arrival"><b>Arrival</b></lable>
                <input type ="text" name="arrival" required>

                <lable for = "phonenumber"><b>Phone Number</b></lable>
                <input type ="text" name="phonenumber" required>

                <lable for = "email"><b>Email</b></lable>
                <input type ="email" name="email" required>

                

                <input type = "submit" name= "create" value="Join">
            </div>

        </form>
    </div>
</body>
</html>