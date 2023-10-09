<?php
Class Konversi {
    function konversi() {
        $this->dasar = array(1=>'SATU','DUA','TIGA','EMPAT','LIMA','ENAM','TUJUH','DELAPAN','SEMBILAN');
        $this->angka = array(1000000000,1000000,1000,100,10,1);
        $this->satuan = array('MILYAR','JUTA','RIBU','RATUS','PULUH','');
    }
    function eja($n) {
        $i=0;
        while($n!=0){
            $count = (int)($n/$this->angka[$i]);
            if($count>=10) $str .= $this->eja($count). " ".$this->satuan[$i]." ";
            else if($count > 0 && $count < 10)
            $str .= $this->dasar[$count] . " ".$this->satuan[$i]." ";
            $n -= $this->angka[$i] * $count;
            $i++;
        }
        $str = preg_replace("/SATU PULUH (\w+)/i","\\1 BELAS",$str);
        $str = preg_replace("/SATU (RIBU|RATUS|PULUH|BELAS)/i","SE\\1",$str);
        return $str;
    }
}
?>