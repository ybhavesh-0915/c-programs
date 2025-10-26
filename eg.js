#!/usr/bin/gjs

imports.gi.versions.Gtk = '4.0';
const { Gtk, GLib } = imports.gi;
const Cairo = imports.cairo;

// Stack implementation with push, pop, peek methods
class Stack {
    constructor(capacity = 4) {
        this.items = [];
        this.capacity = capacity;
    }
    
    push(element) {
        if (this.items.length < this.capacity) {
            this.items.push(element);
            return true;
        }
        return false;
    }
    
    pop() {
        if (!this.isEmpty()) {
            return this.items.pop();
        }
        return null;
    }
    
    peek() {
        if (!this.isEmpty()) {
            return this.items[this.items.length - 1];
        }
        return null;
    }
    
    isEmpty() {
        return this.items.length === 0;
    }
    
    isFull() {
        return this.items.length >= this.capacity;
    }
    
    size() {
        return this.items.length;
    }
    
    clear() {
        this.items = [];
    }
    
    getAll() {
        return [...this.items];
    }
    
    isUniform() {
        if (this.isEmpty() || !this.isFull()) return false;
        const firstColor = this.items[0];
        return this.items.every(color => this.colorsMatch(color, firstColor));
    }
    
    colorsMatch(color1, color2) {
        return Math.abs(color1[0] - color2[0]) < 0.01 &&
               Math.abs(color1[1] - color2[1]) < 0.01 &&
               Math.abs(color1[2] - color2[2]) < 0.01;
    }
    
    // Count consecutive colors from top
    countTopColors() {
        if (this.isEmpty()) return 0;
        
        const topColor = this.peek();
        let count = 0;
        
        for (let i = this.items.length - 1; i >= 0; i--) {
            if (this.colorsMatch(this.items[i], topColor)) {
                count++;
            } else {
                break;
            }
        }
        return count;
    }
}

class WaterSortGame {
    constructor() {
        this.app = new Gtk.Application({
            application_id: 'com.example.watersort',
            flags: 0
        });
        
        this.tubes = [];
        this.selectedTube = -1;
        this.moves = 0;
        this.tubeCapacity = 4;
        this.numTubes = 6;
        
        // Animation properties
        this.animating = false;
        this.animationProgress = 0;
        this.animationFrom = -1;
        this.animationTo = -1;
        this.animationColors = [];
        this.animationTimeoutId = null;
        
        // UI effects
        this.particles = [];
        this.tubeHover = -1;
        this.tubeScale = new Array(6).fill(1.0);
        this.waveTime = 0;
        this.waveTimeoutId = null;
        
        this.colors = [
            [1.0, 0.2, 0.2, 1.0], // Red
            [0.2, 0.4, 1.0, 1.0], // Blue
            [0.2, 0.8, 0.2, 1.0], // Green
            [1.0, 0.8, 0.0, 1.0], // Yellow
        ];
        
        this.app.connect('activate', () => this.onActivate());
    }
    
    onActivate() {
        this.window = new Gtk.ApplicationWindow({
            application: this.app,
            title: 'Water Color Sort - Stack Implementation',
            default_width: 800,
            default_height: 600
        });
        
        const mainBox = new Gtk.Box({
            orientation: Gtk.Orientation.VERTICAL,
            spacing: 20,
            margin_top: 20,
            margin_bottom: 20,
            margin_start: 20,
            margin_end: 20
        });
        
        // Header with moves counter
        const headerBox = new Gtk.Box({
            orientation: Gtk.Orientation.HORIZONTAL,
            spacing: 10,
            halign: Gtk.Align.CENTER
        });
        
        this.movesLabel = new Gtk.Label({
            label: 'Moves: 0',
            css_classes: ['title-2']
        });
        
        const newGameBtn = new Gtk.Button({
            label: 'New Game',
            css_classes: ['suggested-action']
        });
        newGameBtn.connect('clicked', () => this.initGame());
        
        headerBox.append(this.movesLabel);
        headerBox.append(newGameBtn);
        
        // Game area
        this.gameBox = new Gtk.Box({
            orientation: Gtk.Orientation.HORIZONTAL,
            spacing: 15,
            halign: Gtk.Align.CENTER,
            valign: Gtk.Align.CENTER,
            hexpand: true,
            vexpand: true
        });
        
        // Win message
        this.winLabel = new Gtk.Label({
            label: '🎉 You Won! 🎉',
            css_classes: ['title-1'],
            visible: false
        });
        
        mainBox.append(headerBox);
        mainBox.append(this.gameBox);
        mainBox.append(this.winLabel);
        
        this.window.set_child(mainBox);
        this.window.present();
        
        this.initGame();
        this.startWaveAnimation();
    }
    
    initGame() {
        // Clear any running animations
        if (this.animationTimeoutId) {
            GLib.source_remove(this.animationTimeoutId);
            this.animationTimeoutId = null;
        }
        
        this.moves = 0;
        this.selectedTube = -1;
        this.animating = false;
        this.movesLabel.label = 'Moves: 0';
        this.winLabel.visible = false;
        this.particles = [];
        
        // Clear game box
        let child = this.gameBox.get_first_child();
        while (child) {
            const next = child.get_next_sibling();
            this.gameBox.remove(child);
            child = next;
        }
        
        // Initialize tubes as Stacks
        this.tubes = [];
        
        // Create 4 colored tubes and 2 empty tubes
        for (let i = 0; i < 4; i++) {
            const stack = new Stack(this.tubeCapacity);
            for (let j = 0; j < 4; j++) {
                stack.push([...this.colors[i]]);
            }
            this.tubes.push(stack);
        }
        
        // Add 2 empty tubes
        this.tubes.push(new Stack(this.tubeCapacity));
        this.tubes.push(new Stack(this.tubeCapacity));
        
        // Shuffle by randomly pouring between tubes
        for (let mix = 0; mix < 30; mix++) {
            const from = Math.floor(Math.random() * 4);
            const to = Math.floor(Math.random() * 6);
            
            if (from !== to && !this.tubes[from].isEmpty() && !this.tubes[to].isFull()) {
                const color = this.tubes[from].pop();
                this.tubes[to].push(color);
            }
        }
        
        // Create tube UI
        for (let i = 0; i < this.numTubes; i++) {
            const tubeBtn = this.createTubeButton(i);
            this.gameBox.append(tubeBtn);
        }
    }
    
    createTubeButton(index) {
        const btn = new Gtk.Button({
            width_request: 80,
            height_request: 200,
            css_classes: ['tube-button']
        });
        
        const drawingArea = new Gtk.DrawingArea({
            width_request: 80,
            height_request: 200
        });
        
        // Add hover controller
        const motionController = new Gtk.EventControllerMotion();
        motionController.connect('enter', () => {
            this.tubeHover = index;
            this.animateScale(index, 1.1);
        });
        motionController.connect('leave', () => {
            this.tubeHover = -1;
            this.animateScale(index, 1.0);
        });
        btn.add_controller(motionController);
        
        drawingArea.set_draw_func((area, cr, width, height) => {
            cr.save();
            const scale = this.tubeScale[index];
            cr.translate(width / 2, height / 2);
            cr.scale(scale, scale);
            cr.translate(-width / 2, -height / 2);
            
            this.drawTube(cr, width, height, this.tubes[index], index === this.selectedTube, index);
            
            cr.restore();
        });
        
        btn.set_child(drawingArea);
        btn.connect('clicked', () => this.onTubeClick(index));
        
        return btn;
    }
    
    drawTube(cr, width, height, stack, selected, tubeIndex) {
        const tubeX = 10;
        const tubeY = 20;
        const tubeWidth = width - 20;
        const tubeHeight = height - 40;
        
        // Draw glow effect for selected tube
        if (selected) {
            cr.setSourceRGBA(1.0, 0.8, 0.0, 0.3);
            for (let i = 0; i < 3; i++) {
                cr.setLineWidth(8 - i * 2);
                cr.rectangle(tubeX - 3 + i, tubeY - 3 + i, tubeWidth + 6 - i * 2, tubeHeight + 6 - i * 2);
                cr.stroke();
            }
        }
        
        // Draw glass tube with gradient
        const gradient = new Cairo.LinearGradient(tubeX, tubeY, tubeX + tubeWidth, tubeY);
        gradient.addColorStopRGBA(0, 0.8, 0.9, 1.0, 0.3);
        gradient.addColorStopRGBA(0.5, 0.9, 0.95, 1.0, 0.15);
        gradient.addColorStopRGBA(1, 0.8, 0.9, 1.0, 0.3);
        cr.setSource(gradient);
        cr.rectangle(tubeX, tubeY, tubeWidth, tubeHeight);
        cr.fill();
        
        // Calculate how many colors to show during animation
        let colors = stack.getAll();
        let layersToHide = 0;
        
        // During pouring, reduce the visible layers in source tube
        if (this.animating && this.animationFrom === tubeIndex) {
            layersToHide = Math.floor(this.animationColors.length * this.animationProgress);
            colors = colors.slice(0, colors.length - layersToHide);
        }
        
        // During receiving, show filling layers in destination tube
        if (this.animating && this.animationTo === tubeIndex) {
            const layersToAdd = Math.floor(this.animationColors.length * this.animationProgress);
            const receivedColors = this.animationColors.slice(-layersToAdd).reverse();
            colors = [...colors, ...receivedColors];
        }
        
        // Draw water layers from stack
        if (colors.length > 0) {
            const layerHeight = tubeHeight / this.tubeCapacity;
            
            for (let i = 0; i < colors.length; i++) {
                const color = colors[i];
                const y = tubeY + tubeHeight - (i + 1) * layerHeight;
                
                // Main color
                cr.setSourceRGBA(color[0], color[1], color[2], color[3]);
                cr.rectangle(tubeX + 2, y + 2, tubeWidth - 4, layerHeight - 4);
                cr.fill();
                
                // Shine effect
                const shineGradient = new Cairo.LinearGradient(tubeX + 2, y + 2, tubeX + tubeWidth - 2, y + 2);
                shineGradient.addColorStopRGBA(0, 1, 1, 1, 0.4);
                shineGradient.addColorStopRGBA(0.3, 1, 1, 1, 0.1);
                shineGradient.addColorStopRGBA(1, 1, 1, 1, 0);
                cr.setSource(shineGradient);
                cr.rectangle(tubeX + 2, y + 2, tubeWidth * 0.4, layerHeight - 4);
                cr.fill();
                
                // Wave animation for top layer
                if (i === colors.length - 1 && !this.animating) {
                    cr.setSourceRGBA(color[0] * 1.2, color[1] * 1.2, color[2] * 1.2, 0.5);
                    cr.setLineWidth(2);
                    cr.moveTo(tubeX + 2, y + 3 + Math.sin(this.waveTime * 2 + tubeIndex) * 2);
                    for (let x = 0; x < tubeWidth - 4; x += 5) {
                        const waveY = y + 3 + Math.sin(this.waveTime * 2 + tubeIndex + x * 0.1) * 2;
                        cr.lineTo(tubeX + 2 + x, waveY);
                    }
                    cr.stroke();
                }
            }
        }
        
        
        // Draw particles for win celebration
        for (let particle of this.particles) {
            if (particle.tubeIndex === tubeIndex) {
                cr.setSourceRGBA(particle.color[0], particle.color[1], particle.color[2], particle.alpha);
                cr.arc(particle.x, particle.y, particle.size, 0, 2 * Math.PI);
                cr.fill();
            }
        }
        
        // Draw tube outline
        cr.setSourceRGBA(0.2, 0.2, 0.3, 0.8);
        cr.setLineWidth(selected ? 3 : 2);
        cr.rectangle(tubeX, tubeY, tubeWidth, tubeHeight);
        cr.stroke();
    }
    
    onTubeClick(index) {
        if (this.animating) return;
        
        if (this.selectedTube === -1) {
            // Select tube if it has water (using peek to check)
            if (this.tubes[index].peek() !== null) {
                this.selectedTube = index;
                this.animateScale(index, 1.15);
                this.refreshDisplay();
            }
        } else {
            // Try to pour water
            if (this.selectedTube !== index) {
                if (this.canPour(this.selectedTube, index)) {
                    this.animatePour(this.selectedTube, index);
                } else {
                    // Shake animation for invalid move
                    this.shakeAnimation(index);
                }
            }
            this.animateScale(this.selectedTube, 1.0);
            this.selectedTube = -1;
            this.refreshDisplay();
        }
    }
    
    canPour(fromIndex, toIndex) {
        const fromStack = this.tubes[fromIndex];
        const toStack = this.tubes[toIndex];
        
        // Can't pour from empty tube
        if (fromStack.isEmpty()) return false;
        
        // Can't pour to full tube
        if (toStack.isFull()) return false;
        
        // Can pour to empty tube
        if (toStack.isEmpty()) return true;
        
        // Can only pour if colors match (using peek)
        const fromColor = fromStack.peek();
        const toColor = toStack.peek();
        
        return fromStack.colorsMatch(fromColor, toColor);
    }
    
    pourWater(fromIndex, toIndex) {
        const fromStack = this.tubes[fromIndex];
        const toStack = this.tubes[toIndex];
        
        // Pour all consecutive matching colors from top
        while (!fromStack.isEmpty() && 
               !toStack.isFull() &&
               (toStack.isEmpty() || fromStack.colorsMatch(fromStack.peek(), toStack.peek()))) {
            const color = fromStack.pop();
            toStack.push(color);
        }
    }
    
    checkWin() {
        for (let tube of this.tubes) {
            if (tube.isEmpty()) continue;
            
            // Each non-empty tube must be full and uniform
            if (!tube.isUniform()) return false;
        }
        return true;
    }
    
    refreshDisplay() {
        let child = this.gameBox.get_first_child();
        while (child) {
            const drawingArea = child.get_child();
            if (drawingArea) {
                drawingArea.queue_draw();
            }
            child = child.get_next_sibling();
        }
    }
    
    animatePour(fromIndex, toIndex) {
        this.animating = true;
        this.animationFrom = fromIndex;
        this.animationTo = toIndex;
        this.animationProgress = 0;
        
        // Determine which colors will be poured
        const fromStack = this.tubes[fromIndex];
        const toStack = this.tubes[toIndex];
        
        this.animationColors = [];
        const tempColors = fromStack.getAll();
        const topColor = fromStack.peek();
        
        // Count how many of the top color will be poured
        let count = 0;
        for (let i = tempColors.length - 1; i >= 0 && count < (this.tubeCapacity - toStack.size()); i--) {
            if (fromStack.colorsMatch(tempColors[i], topColor)) {
                this.animationColors.push(tempColors[i]);
                count++;
            } else {
                break;
            }
        }
        
        const duration = 600; // milliseconds
        const startTime = Date.now();
        
        const animate = () => {
            const elapsed = Date.now() - startTime;
            this.animationProgress = Math.min(elapsed / duration, 1);
            
            // Ease-in-out animation
            const easeProgress = this.animationProgress < 0.5
                ? 2 * this.animationProgress * this.animationProgress
                : 1 - Math.pow(-2 * this.animationProgress + 2, 2) / 2;
            
            this.animationProgress = easeProgress;
            this.refreshDisplay();
            
            if (elapsed < duration) {
                this.animationTimeoutId = GLib.timeout_add(GLib.PRIORITY_DEFAULT, 16, () => {
                    animate();
                    return false;
                });
            } else {
                // Complete the pour using stack operations
                this.pourWater(fromIndex, toIndex);
                this.moves++;
                this.movesLabel.label = `Moves: ${this.moves}`;
                this.animating = false;
                this.animationColors = [];
                this.animationTimeoutId = null;
                this.refreshDisplay();
                
                if (this.checkWin()) {
                    this.celebrateWin();
                }
            }
        };
        
        animate();
    }
    
    animateScale(index, targetScale) {
        const startScale = this.tubeScale[index];
        const duration = 200;
        const startTime = Date.now();
        
        const animate = () => {
            const elapsed = Date.now() - startTime;
            const progress = Math.min(elapsed / duration, 1);
            
            this.tubeScale[index] = startScale + (targetScale - startScale) * progress;
            this.refreshDisplay();
            
            if (progress < 1) {
                GLib.timeout_add(GLib.PRIORITY_DEFAULT, 16, () => {
                    animate();
                    return false;
                });
            }
        };
        
        animate();
    }
    
    shakeAnimation(index) {
        const shakes = 6;
        let count = 0;
        const originalScale = this.tubeScale[index];
        
        const shake = () => {
            if (count < shakes) {
                this.tubeScale[index] = originalScale + (count % 2 === 0 ? 0.05 : -0.05);
                this.refreshDisplay();
                count++;
                
                GLib.timeout_add(GLib.PRIORITY_DEFAULT, 50, () => {
                    shake();
                    return false;
                });
            } else {
                this.tubeScale[index] = originalScale;
                this.refreshDisplay();
            }
        };
        
        shake();
    }
    
    celebrateWin() {
        this.winLabel.visible = true;
        
        // Create particle effect
        this.particles = [];
        for (let i = 0; i < this.numTubes; i++) {
            for (let j = 0; j < 20; j++) {
                this.particles.push({
                    tubeIndex: i,
                    x: 40 + Math.random() * 20,
                    y: 100,
                    vx: (Math.random() - 0.5) * 4,
                    vy: -Math.random() * 8 - 5,
                    color: this.colors[Math.floor(Math.random() * this.colors.length)],
                    alpha: 1.0,
                    size: Math.random() * 4 + 2
                });
            }
        }
        
        const animateParticles = () => {
            let allGone = true;
            
            for (let particle of this.particles) {
                particle.x += particle.vx;
                particle.y += particle.vy;
                particle.vy += 0.3; // gravity
                particle.alpha -= 0.02;
                
                if (particle.alpha > 0) {
                    allGone = false;
                }
            }
            
            this.refreshDisplay();
            
            if (!allGone) {
                GLib.timeout_add(GLib.PRIORITY_DEFAULT, 16, () => {
                    animateParticles();
                    return false;
                });
            } else {
                this.particles = [];
            }
        };
        
        animateParticles();
        
        // Show win dialog
        this.showWinDialog();
    }
    
    showWinDialog() {
        const dialog = new Gtk.MessageDialog({
            transient_for: this.window,
            modal: true,
            buttons: Gtk.ButtonsType.NONE,
            message_type: Gtk.MessageType.INFO,
            text: '🎉 Congratulations! 🎉'
        });
        
        dialog.set_property('secondary-text', 
            `You completed the puzzle in ${this.moves} moves!\n\nWell done! 🏆`);
        
        // Add custom buttons
        dialog.add_button('New Game', Gtk.ResponseType.ACCEPT);
        dialog.add_button('Close', Gtk.ResponseType.CLOSE);
        
        // Make the New Game button prominent
        const newGameButton = dialog.get_widget_for_response(Gtk.ResponseType.ACCEPT);
        newGameButton.add_css_class('suggested-action');
        
        dialog.connect('response', (dialog, response) => {
            if (response === Gtk.ResponseType.ACCEPT) {
                this.initGame();
            }
            dialog.close();
        });
        
        dialog.present();
    }
    
    startWaveAnimation() {
        // Continuous wave animation
        if (this.waveTimeoutId) {
            GLib.source_remove(this.waveTimeoutId);
        }
        
        const updateWave = () => {
            this.waveTime += 0.05;
            if (!this.animating) {
                this.refreshDisplay();
            }
            return true;
        };
        
        this.waveTimeoutId = GLib.timeout_add(GLib.PRIORITY_DEFAULT, 50, updateWave);
    }
    
    run(argv) {
        return this.app.run(argv);
    }
}

const game = new WaterSortGame();
game.run(ARGV);