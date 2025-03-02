// UMD_CameraDriver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <windows.h>
#include <mfapi.h>
#include <mfidl.h>
#include <Mferror.h>
#include <strsafe.h>

// Define the IOCTL command for the AVStream driver
#define IOCTL_CAMERA_GET_FRAME CTL_CODE(FILE_DEVICE_UNKNOWN, 0x800, METHOD_BUFFERED, FILE_ANY_ACCESS)

int main() {
    HRESULT hr;
    IMFMediaSource* pMediaSource = NULL;
    IMFMediaType* pMediaType = NULL;
    IUnknown* pUnknown = NULL;
    HANDLE hDevice = INVALID_HANDLE_VALUE;
    BYTE* pBuffer = NULL;
    DWORD bytesRead = 0;

    // Open the device handle
    //hDevice = CreateFile(L"\\\\.\\MyCameraDevice", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    hDevice = CreateFile(L"\\_SB.PCI0.GP17.XHC0.RHUB.PRT3.WCAM", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hDevice == INVALID_HANDLE_VALUE) {
        printf("Failed to open device. Error: %d\n", GetLastError());
        return 1;
    }

    // Send IOCTL command to get a frame from the camera
    hr = DeviceIoControl(hDevice, IOCTL_CAMERA_GET_FRAME, NULL, 0, pBuffer, 1024 * 1024, &bytesRead, NULL);
    if (FAILED(hr)) {
        printf("Failed to send IOCTL command. Error: %d\n", hr);
        CloseHandle(hDevice);
        return 1;
    }

    // Process the received frame (for simplicity, just print the size)
    printf("Received frame size: %d bytes\n", bytesRead);

    // Clean up
    CloseHandle(hDevice);
    CoTaskMemFree(pBuffer);

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
