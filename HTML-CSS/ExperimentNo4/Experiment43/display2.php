<?php
require_once('connection.php');

$sql = "SELECT * from flight";
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
            color: Blue;
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

    <section>
        <h1>Data Of Database<h1>
        <table>
            <?php
                 
                 $sth = $db->query($sql);
                    while( $row = $sth->fetch(PDO::FETCH_ASSOC) ) {

                        echo "<tr>";
                        echo "<td>" . $row["passenger"] . "</td>";
                        echo "<td>" . $row["afrom"] . "</td>";
                        echo "<td>" . $row["tob"] . "</td>";
                        echo "<td>" . $row["departure"] . "</td>";
                        echo "<td>" . $row["arrival"] . "</td>";
                        echo "<td>" . $row["phonenumber"] . "</td>";
                        echo "<td>" . $row["email"] . "</td>";
                        echo "</tr>";
                    
                }
                

            ?>


          
        </table>
    </section>
</body>
 
</html>