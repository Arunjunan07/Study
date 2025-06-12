<style>
	table,tr,td,th{
		border-collapse:collapse;
		border:2px solid black;
		padding:20px;
		
	}
	tr{
		text-align:center;
	}
</style>
<?php
$conn=mysqli_connect("localhost","root","","store");
if ($conn){
	echo "connected";
}
$a=intval($_POST['t1']);
$b=$_POST['t2'];
$c=$_POST['t3'];
$d=$_POST['t4'];
$w=$_POST['t5'];
$y=intval($_POST['t6']);
$i=intval($_POST['t7']);
$q='insert into items values('.$a.','.'"'.$b.'"'.','.$c.','.$d.')';
//$q='delete from items where item_No='.$a;
mysqli_query($conn,$q);
echo " inserted";
if($w==''){
	echo '<br>Nothing to view';
}
else{
	$r='select * from items where price='.$w;
	$v=mysqli_query($conn,$r);
	$z=mysqli_num_rows($v);
	if($z==0){
		echo'No records found';
	}
	else{
					echo'<br><br><table><th>ITEM NO</th><th>ITEM NAME</th><th>PRICE</th><th>QUANTITY</th>';

		while($row=mysqli_fetch_array($v))
		{
			echo'<tr><td>'.$row[0].'<td>'.$row[1].'<td>'.$row[2].'<td>'.$row[3].'</tr>';
			
		}
		echo'</table>';
	}
}
$cc='update items set price='.$i.'where 
item_No='.$y;
mysqli_query($conn,$cc);
$vv=mysqli_affected_rows($conn);
echo $vv;	
mysqli_close($conn);

?>