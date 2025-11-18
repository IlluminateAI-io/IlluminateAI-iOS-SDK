// swift-tools-version: 6.0
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "RingoAI_SDK",
	defaultLocalization: "en",
	platforms: [
		.iOS(.v15)
	],
    products: [
		.library(
			name: "RingoAI.xcframework",
			targets: ["RingoAI.xcframework"]),
		.library(
			name: "RingoAISupport.xcframework",
			targets: ["RingoAISupport.xcframework"]),
		.library(
			name: "elfSupport.xcframework",
			targets: ["elfSupport.xcframework"])
    ],
    targets: [
		.binaryTarget(
			name: "RingoAI.xcframework",
			path: "xcframeworks/RingoAI.xcframework"
		),
		.binaryTarget(
			name: "RingoAISupport.xcframework",
			path: "xcframeworks/RingoAISupport.xcframework"
		),
		.binaryTarget(
			name: "elfSupport.xcframework",
			path: "xcframeworks/elfSupport.xcframework"
		)
    ]
)
