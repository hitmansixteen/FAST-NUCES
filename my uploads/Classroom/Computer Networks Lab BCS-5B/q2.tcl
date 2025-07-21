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
$ns color 0 blue

$ns rtproto DV 


for {set i 0} {$i <= 6} {incr i} {
	set nodes($i) [$ns node]
}

for {set i 1} {$i <= 6} {incr i} {
	$ns duplex-link $nodes(0) $nodes($i) 512Kb 10ms SFQ
}


$ns duplex-link $nodes(6) $nodes(0) 512Kb 10ms SFQ

$ns duplex-link-op $nodes(0) $nodes(1) orient left-up
$ns duplex-link-op $nodes(0) $nodes(2) orient right-up
$ns duplex-link-op $nodes(0) $nodes(3) orient right
$ns duplex-link-op $nodes(0) $nodes(4) orient right-down
$ns duplex-link-op $nodes(0) $nodes(5) orient left-down
$ns duplex-link-op $nodes(0) $nodes(6) orient left

 




set tcp0 [new Agent/TCP]
$ns attach-agent $nodes(1) $tcp0        
set sink0 [new Agent/TCPSink]
$ns attach-agent $nodes(4) $sink0
$ns connect $tcp0 $sink0
set ftp0 [new Application/FTP]
$ftp0 attach-agent $tcp0

set udp0 [new Agent/UDP]
$ns attach-agent $nodes(2) $udp0
set null0 [new Agent/Null]
$ns attach-agent $nodes(5) $null0
$ns connect $udp0 $null0
set cbr0 [new Application/Traffic/CBR]
$cbr0 set packetSize_ 2560
$cbr0 set interval 0.01 
$cbr0 attach-agent $udp0

$udp0 set fid_ 0
$tcp0 set fid_ 1


$ns at 0.1 "$ftp0 start"

$ns at 1.5 "$ftp0 stop"

$ns at 0.2 "$cbr0 start"

$ns at 1.3 "$cbr0 stop"

$ns rtmodel-at 0.5 down $nodes(0) $nodes(5)

$ns rtmodel-at 0.9 up $nodes(0) $nodes(5)

$ns rtmodel-at 0.7 down $nodes(0) $nodes(4)

$ns rtmodel-at 1.2 up $nodes(0) $nodes(4)

$ns at 2.0 "finish"

$ns run



