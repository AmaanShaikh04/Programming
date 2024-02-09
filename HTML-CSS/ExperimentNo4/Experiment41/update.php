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
                $bookname =$_POST['bookname'];
                $isbn =$_POST['isbn'];
                $author = $_POST['author'];
                $publisher =$_POST['publisher'];
                $id = $_POST['id'];

                $sql = "UPDATE books SET bookname = '$bookname', isbn = '$isbn', author = '$author' ,publisher = '$publisher'  WHERE id = '$id';";
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
                <h1>Updation of book</h1>
                <p>Fill up the form with correct values</p>
                <lable for = "bookname"><b>Book Name</b></lable>
                <input type ="text" name="bookname" required>

                <lable for = "isbn"><b>ISBN No</b></lable>
                <input type ="text" name="isbn" required>

                <lable for = "author"><b>Author Name</b></lable>
                <input type ="text" name="author" required>

                <lable for = "publisher"><b>Publisher Name</b></lable>
                <input type ="text" name="publisher" required>

                <lable for = "id"><b>ID for updation</b></lable>
                <input type ="text" name="id" required>

                

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