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
    
    echo "<table border=1><tr><td></td>";
    for($i=1; $i <= $upperLimit; $i++){
        
        echo "<td>$i</td>";
    }
    echo "</tr>";

    for($i=1; $i <= $upperLimit; $i++){
        echo "<tr>";
        echo "<td>$i</td>";
        for($j=1; $j <= $upperLimit; $j++){
        $temp = $i*$j;
        echo "<td>$temp</td>";
    }
    echo "</tr>";
    }

?>