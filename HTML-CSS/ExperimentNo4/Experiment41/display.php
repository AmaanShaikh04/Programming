<?php
require_once('connection.php');

$sql = "SELECT * from books";
$result = $db->query($sql);
?>
<!DOCTYPE html>
<html lang="en">
 
<head>
    <meta charset="UTF-8">
    <title>diplay..</title>
    <style>
        table {
            margin: 0 auto;
            font-size: large;
            border: 1px solid black;
        }
 
        h1 {
            text-align: center;
            color: black;
            font-size: xx-large;
            font-family: 'Gill Sans', 'Gill Sans MT',
            ' Calibri', 'Trebuchet MS', 'sans-serif';
        }
 
        td {
            background-color: #E4F5D4;
            border: 1px solid black;
        }
 
        th,td {
            font-weight: bold;
            border: 1px solid black;
            padding: 10px;
            text-align: center;
        }
 
        td {
            font-weight: lighter;
        }
    </style>
    <link rel = "stylesheet" href = "first.css">
</head>
 
<body>
<div class="navbar">
            <a  href="registration.php">Insert</a> 
            <a href="display.php">Display</a> 
            <a href="update.php">Update</a> 
            <a href="delete.php">Delete</a>
    </div>
    <section>
       <br><br><br>
        <table>
            <?php
                 
                 $sth = $db->query($sql);
                    while( $row = $sth->fetch(PDO::FETCH_ASSOC) ) {

                        echo "<tr>";
                        echo "<td>" . $row["bookname"] . "</td>";
                        echo "<td>" . $row["isbn"] . "</td>";
                        echo "<td>" . $row["author"] . "</td>";
                        echo "<td>" . $row["publisher"] . "</td>";
                        echo "</tr>";
                    
                }
                

            ?>


          
        </table>
    </section>
</body>
 
</html>