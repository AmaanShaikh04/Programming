<?php
session_start();
if (!isset($_SESSION['email'])) {
    header("Location: index.html");
    exit();
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Dashboard</title>
    <link rel="stylesheet" type="text/css" href="css/style.css">
</head>
<body>
    <div class="container">
        <h2>Welcome to Dashboard</h2>
        <p>You are logged in with email: <?php echo $_SESSION['email']; ?></p>
    </div>
</body>
</html>
