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
                $employeename =$_POST['employeename'];
                $employeeid =$_POST['employeeid'];
                $department = $_POST['department'];
                $phonenumber =$_POST['phonenumber'];
                $joindate= $_POST['joindate'];
                

                $sql = "UPDATE employee SET employeename = '$employeename', employeeid = '$employeeid', department = '$department' ,phonenumber = '$phonenumber' ,joindate='$joindate' WHERE employeeid = '$employeeid';";
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
                <lable for = "employeename"><b>Employee Name</b></lable>
                <input type ="text" name="employeename" required>

                <lable for = "employeeid"><b>Employee ID</b></lable>
                <input type ="text" name="employeeid" required>

                <lable for = "department"><b>Department </b></lable>
                <input type ="text" name="department" required>

                <lable for = "phonenumber"><b>Phone Number</b></lable>
                <input type ="text" name="phonenumber" required>

                <lable for = "joindate"><b>Join Date</b></lable>
                <input type ="text" name="joindate" required>

                

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