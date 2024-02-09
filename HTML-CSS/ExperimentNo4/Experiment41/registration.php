<?php
require_once('connection.php');
?>
<html>
<head>
<title>
    Book Registration
</title>
<link rel = "stylesheet" href = "first.css">
</head>
<body>
    <div>
        <?php
            if(isset($_POST['create']))
            {
                $bookname =$_POST['bookname'];
                $isbn =$_POST['isbn'];
                $author = $_POST['author'];
                $publisher =$_POST['publisher'];
                

                $sql = "INSERT INTO books (bookname, isbn, author, publisher) VALUES(?,?,?,?)";
                $stmtinsert = $db->prepare($sql);
                $result = $stmtinsert->execute([$bookname, $isbn, $author, $publisher]);

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
                <h1>Book Feeding</h1>
                <p>Fill up the form with correct values</p>
                <lable for = "bookname"><b>Book Name</b></lable>
                <input type ="text" name="bookname" required>

                <lable for = "isbn"><b>ISBN No</b></lable>
                <input type ="text" name="isbn" required>

                <lable for = "author"><b>Author Name</b></lable>
                <input type ="text" name="author" required>

                <lable for = "publisher"><b>Publisher Name</b></lable>
                <input type ="text" name="publisher" required>

               

                <input type = "submit" name= "create" value="FEED">
            </div>

        </form>
    </div>
</body>
</html>