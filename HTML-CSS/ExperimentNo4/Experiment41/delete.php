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
            if(isset($_POST['del']))
            {
                
                $id = $_POST['id'];
                
                

                $sql = "DELETE FROM books where id = $id;";
                $result = $db->query($sql);

                if($result)
                {
                   echo 'Deleted Successfully';
                }
                else{
                    echo 'There is an error';
                }
            }
        ?>
    </div>
    <div>
    <div class="navbar">
            <a  href="registration.php">Insert</a> 
            <a href="display.php">Display</a> 
            <a href="update.php">Update</a> 
            <a href="delete.php">Delete</a>
    </div>
        <form action="delete.php" method="post">
        
            <div class = "container">
                <h1>Deletion</h1>
                
            
                <lable for = "id"><b>ID Address to delete record</b></lable>
                <input type ="text" name="id" required>
                <input type = "submit" name= "del" value="delete record">
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