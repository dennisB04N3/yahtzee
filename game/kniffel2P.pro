QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        board.cpp \
        button.cpp \
        confirmationwindow.cpp \
        dice.cpp \
        dicetextures.cpp \
        displaymanager.cpp \
        game.cpp \
        main.cpp \
        player.cpp \
        playerscore.cpp \
        pointcard.cpp \
        textfield.cpp \
        winnerwindow.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
# copy binaries to build folders
copydata.commands = $(COPY_DIR) $$shell_path($$PWD\res\bin) $$shell_path($$OUT_PWD)
first.depends = $(first) copydata
export(first.depends)
export(copydata.commands)
QMAKE_EXTRA_TARGETS += first copydata


HEADERS += \
    board.h \
    button.h \
    confirmationwindow.h \
    dice.h \
    dicetextures.h \
    displaymanager.h \
    game.h \
    player.h \
    playerscore.h \
    pointcard.h \
    textfield.h \
    src/include/SFML/Audio.hpp \
    src/include/SFML/Audio/AlResource.hpp \
    src/include/SFML/Audio/Export.hpp \
    src/include/SFML/Audio/InputSoundFile.hpp \
    src/include/SFML/Audio/Listener.hpp \
    src/include/SFML/Audio/Music.hpp \
    src/include/SFML/Audio/OutputSoundFile.hpp \
    src/include/SFML/Audio/Sound.hpp \
    src/include/SFML/Audio/SoundBuffer.hpp \
    src/include/SFML/Audio/SoundBufferRecorder.hpp \
    src/include/SFML/Audio/SoundFileFactory.hpp \
    src/include/SFML/Audio/SoundFileFactory.inl \
    src/include/SFML/Audio/SoundFileReader.hpp \
    src/include/SFML/Audio/SoundFileWriter.hpp \
    src/include/SFML/Audio/SoundRecorder.hpp \
    src/include/SFML/Audio/SoundSource.hpp \
    src/include/SFML/Audio/SoundStream.hpp \
    src/include/SFML/Config.hpp \
    src/include/SFML/GpuPreference.hpp \
    src/include/SFML/Graphics.hpp \
    src/include/SFML/Graphics/BlendMode.hpp \
    src/include/SFML/Graphics/CircleShape.hpp \
    src/include/SFML/Graphics/Color.hpp \
    src/include/SFML/Graphics/ConvexShape.hpp \
    src/include/SFML/Graphics/Drawable.hpp \
    src/include/SFML/Graphics/Export.hpp \
    src/include/SFML/Graphics/Font.hpp \
    src/include/SFML/Graphics/Glsl.hpp \
    src/include/SFML/Graphics/Glsl.inl \
    src/include/SFML/Graphics/Glyph.hpp \
    src/include/SFML/Graphics/Image.hpp \
    src/include/SFML/Graphics/PrimitiveType.hpp \
    src/include/SFML/Graphics/Rect.hpp \
    src/include/SFML/Graphics/Rect.inl \
    src/include/SFML/Graphics/RectangleShape.hpp \
    src/include/SFML/Graphics/RenderStates.hpp \
    src/include/SFML/Graphics/RenderTarget.hpp \
    src/include/SFML/Graphics/RenderTexture.hpp \
    src/include/SFML/Graphics/RenderWindow.hpp \
    src/include/SFML/Graphics/Shader.hpp \
    src/include/SFML/Graphics/Shape.hpp \
    src/include/SFML/Graphics/Sprite.hpp \
    src/include/SFML/Graphics/Text.hpp \
    src/include/SFML/Graphics/Texture.hpp \
    src/include/SFML/Graphics/Transform.hpp \
    src/include/SFML/Graphics/Transformable.hpp \
    src/include/SFML/Graphics/Vertex.hpp \
    src/include/SFML/Graphics/VertexArray.hpp \
    src/include/SFML/Graphics/VertexBuffer.hpp \
    src/include/SFML/Graphics/View.hpp \
    src/include/SFML/Main.hpp \
    src/include/SFML/Network.hpp \
    src/include/SFML/Network/Export.hpp \
    src/include/SFML/Network/Ftp.hpp \
    src/include/SFML/Network/Http.hpp \
    src/include/SFML/Network/IpAddress.hpp \
    src/include/SFML/Network/Packet.hpp \
    src/include/SFML/Network/Socket.hpp \
    src/include/SFML/Network/SocketHandle.hpp \
    src/include/SFML/Network/SocketSelector.hpp \
    src/include/SFML/Network/TcpListener.hpp \
    src/include/SFML/Network/TcpSocket.hpp \
    src/include/SFML/Network/UdpSocket.hpp \
    src/include/SFML/OpenGL.hpp \
    src/include/SFML/System.hpp \
    src/include/SFML/System/Clock.hpp \
    src/include/SFML/System/Err.hpp \
    src/include/SFML/System/Export.hpp \
    src/include/SFML/System/FileInputStream.hpp \
    src/include/SFML/System/InputStream.hpp \
    src/include/SFML/System/Lock.hpp \
    src/include/SFML/System/MemoryInputStream.hpp \
    src/include/SFML/System/Mutex.hpp \
    src/include/SFML/System/NativeActivity.hpp \
    src/include/SFML/System/NonCopyable.hpp \
    src/include/SFML/System/Sleep.hpp \
    src/include/SFML/System/String.hpp \
    src/include/SFML/System/String.inl \
    src/include/SFML/System/Thread.hpp \
    src/include/SFML/System/Thread.inl \
    src/include/SFML/System/ThreadLocal.hpp \
    src/include/SFML/System/ThreadLocalPtr.hpp \
    src/include/SFML/System/ThreadLocalPtr.inl \
    src/include/SFML/System/Time.hpp \
    src/include/SFML/System/Utf.hpp \
    src/include/SFML/System/Utf.inl \
    src/include/SFML/System/Vector2.hpp \
    src/include/SFML/System/Vector2.inl \
    src/include/SFML/System/Vector3.hpp \
    src/include/SFML/System/Vector3.inl \
    src/include/SFML/Window.hpp \
    src/include/SFML/Window/Clipboard.hpp \
    src/include/SFML/Window/Context.hpp \
    src/include/SFML/Window/ContextSettings.hpp \
    src/include/SFML/Window/Cursor.hpp \
    src/include/SFML/Window/Event.hpp \
    src/include/SFML/Window/Export.hpp \
    src/include/SFML/Window/GlResource.hpp \
    src/include/SFML/Window/Joystick.hpp \
    src/include/SFML/Window/Keyboard.hpp \
    src/include/SFML/Window/Mouse.hpp \
    src/include/SFML/Window/Sensor.hpp \
    src/include/SFML/Window/Touch.hpp \
    src/include/SFML/Window/VideoMode.hpp \
    src/include/SFML/Window/Window.hpp \
    src/include/SFML/Window/WindowHandle.hpp \
    src/include/SFML/Window/WindowStyle.hpp \
    winnerwindow.h

INCLUDEPATH += src\include
DEPENDPATH += src\include

CONFIG(debug, debug|release): LIBS += -L$$PWD\src\libs\ \
    -lsfml-audio-d \
    -lsfml-graphics-d \
    -lsfml-main-d \
    -lsfml-network-d \
    -lsfml-system-d \
    -lsfml-window-d

CONFIG(release, debug|release): LIBS += -L$$PWD\src\libs\ \
    -lsfml-audio \
    -lsfml-graphics \
    -lsfml-main \
    -lsfml-network \
    -lsfml-system \
    -lsfml-window

DISTFILES += \
    res/1eye.png \
    res/1eyeS.png \
    res/2eye.png \
    res/2eyeS.png \
    res/3eye.png \
    res/3eyeS.png \
    res/4eye.png \
    res/4eyeS.png \
    res/5eye.png \
    res/5eyeS.png \
    res/6eye.png \
    res/6eyeS.png \
    res/arial.ttf \
    res/background.png \
    res/bin/sfml-audio-2.dll \
    res/bin/sfml-audio-d-2.dll \
    res/bin/sfml-graphics-2.dll \
    res/bin/sfml-graphics-d-2.dll \
    res/bin/sfml-network-2.dll \
    res/bin/sfml-network-d-2.dll \
    res/bin/sfml-system-2.dll \
    res/bin/sfml-system-d-2.dll \
    res/bin/sfml-window-2.dll \
    res/bin/sfml-window-d-2.dll \
    res/card.png \
    res/dice_texture.png \
    res/false.png \
    res/player1_field.png \
    res/player2_field.png \
    res/true.png \
    src/libs/libsfml-audio-d.a \
    src/libs/libsfml-audio.a \
    src/libs/libsfml-graphics-d.a \
    src/libs/libsfml-graphics.a \
    src/libs/libsfml-main-d.a \
    src/libs/libsfml-main.a \
    src/libs/libsfml-network-d.a \
    src/libs/libsfml-network.a \
    src/libs/libsfml-system-d.a \
    src/libs/libsfml-system.a \
    src/libs/libsfml-window-d.a \
    src/libs/libsfml-window.a
