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

            if(isset($_POST['update']))
            {
                $firstname =$_POST['firstname'];
                $lastname =$_POST['lastname'];
                $roll = $_POST['roll'];
                $phonenumber =$_POST['phonenumber'];
                $password = $_POST['password'];
                

                $sql = "UPDATE users SET firstname = '$firstname', lastname = '$lastname', roll = '$roll' ,phonenumber = '$phonenumber' ,password='$password' WHERE roll = '$roll';";
                $result = $db->query($sql);

                if($result)
                {
                    
                }
                else{
                    echo 'There is an error';
                }
            }
        ?>
    </div>
    <div>
        <form action="update.php" method="post">
        <div class="navbar">
            <a  href="registration.php">Insert</a> 
            <a href="display.php">Display</a> 
            <a href="update.php">Update</a> 
            <a href="delete.php">Delete</a>
    </div>
            <div class = "container">
                <h1>Updation</h1>
                <p>Fill up the form with correct values</p>
                <lable for = "firstname"><b>First Name</b></lable>
                <input type ="text" name="firstname" required>

                <lable for = "lastname"><b>last Name</b></lable>
                <input type ="text" name="lastname" required>

                <lable for = "roll"><b>Roll Address</b></lable>
                <input type ="text" name="roll" required>

                <lable for = "phonenumber"><b>Phone Number</b></lable>
                <input type ="text" name="phonenumber" required>

                <lable for = "password"><b>Password</b></lable>
                <input type ="password" name="password" required>

                

                <input type = "submit" name= "update" value="Update">
                <div>
                    <?php
                        require_once('display2.php');
                    ?>

            </div>
            </div>
            
        </form>
    </div>
</body>
</html>