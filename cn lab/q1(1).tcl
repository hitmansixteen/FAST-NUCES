set ns [new Simulator]

set nf [open out.nam w]
$ns namtrace-all $nf

#Finish procedure to open file using nam to visulaize our network
proc finish {} {
        global ns nf
        $ns flush-trace
        close $nf
        exec nam out.nam &
        exit 0
}

$ns color 1 red

$ns rtproto DV 


for {set i 0} {$i <= 6} {incr i} {
	set nodes($i) [$ns node]
}

for {set i 0} {$i < 6} {incr i} {
	$ns duplex-link $nodes($i) $nodes([expr $i + 1]) 512Kb 5ms DropTail
}


$ns duplex-link $nodes(6) $nodes(0) 512Kb 5ms DropTail  

$ns duplex-link-op $nodes(0) $nodes(1) orient right
$ns duplex-link-op $nodes(1) $nodes(2) orient right
$ns duplex-link-op $nodes(2) $nodes(3) orient down 
$ns duplex-link-op $nodes(3) $nodes(4) orient left
$ns duplex-link-op $nodes(4) $nodes(5) orient left 
$ns duplex-link-op $nodes(5) $nodes(6) orient left
$ns duplex-link-op $nodes(6) $nodes(0) orient up
 



set udp0 [new Agent/UDP]
$ns attach-agent $nodes(0) $udp0


set null0 [new Agent/Null]
$ns attach-agent $nodes(3) $null0

$ns connect $udp0 $null0

$udp0 set fid_ 1


set cbr0 [new Application/Traffic/CBR]
$cbr0 set packetSize_ 1000

$cbr0 set interval 0.01 


$cbr0 attach-agent $udp0


$ns at 0.02 "$cbr0 start"

$ns rtmodel-at 0.40 down $nodes(2) $nodes(3)

$ns rtmodel-at 1.0 up $nodes(2) $nodes(3)


$ns at 1.5 "$cbr0 stop"

$ns at 2.0 "finish"

$ns run



