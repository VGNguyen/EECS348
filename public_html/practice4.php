<!DOCTYPE html>
<html>
<head>


</head>

<body>


<form action="practice4.php" method="POST">

<label>Enter a number to print times tables out to:</label><br>
<input type="text" name="upperLimit"> <br>

<input type="submit" value="Enter">


</form>
</body>
</html>

<?php

    $upperLimit = $_POST["upperLimit"];
    echo "&nbsp&nbsp&nbsp";
    for($i=1; $i <= $upperLimit; $i++){
        
        echo $i . " ";
    }
    echo nl2br("\n");
    for($i=1; $i <= $upperLimit; $i++){
        echo $i . "   ";
        for($j=1; $j <= $upperLimit; $j++){
        echo $i*$j . " ";
    }
    echo nl2br("\n");
    }

?>