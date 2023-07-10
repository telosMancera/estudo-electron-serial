let testItCalled = 0;

async function testIt() {
    if (testItCalled === 1) {
        console.log('Function is still running!')
        return;
    }

    testItCalled = 1
    const filters = [
        { usbVendorId: 0x2341, usbProductId: 0x0043 },
        { usbVendorId: 0x2341, usbProductId: 0x0001 }
    ]
    try {
        const port = await navigator.serial.requestPort({ filters })
        const portInfo = port.getInfo()
        document.getElementById('device-name').innerHTML = `vendorId: ${portInfo.usbVendorId} | productId: ${portInfo.usbProductId} `

        await port.open({ baudRate: 115200 })
        
        const reader = port.readable.getReader();
        
        // Listen to data coming from the serial device.
        while (true) {
            const { value, done } = await reader.read();
            if (done) {
                // Allow the serial port to be closed later.
                reader.releaseLock();
                break;
            }
            // value is a Uint8Array.
            console.log(value);
            document.getElementById('device-data').innerHTML = `${value}`
        }




    } catch (ex) {
        if (ex.name === 'NotFoundError') {
            document.getElementById('device-name').innerHTML = 'Device NOT found'
        } else {
            document.getElementById('device-name').innerHTML = ex
        }
    }

    testItCalled = 0
}

document.getElementById('clickme').addEventListener('click', testIt)
