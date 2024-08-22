const {app, BrowserWindow} = require("electron");
function ElectronMainMethod(){
    const launchWindow = new BrowserWindow({
        title: "website",
        width: 1950,
        height: 1100

    });

    const appURL = "http://127.0.0.1:8000/";
    launchWindow.loadURL(appURL);
}

app.whenReady().then(ElectronMainMethod)